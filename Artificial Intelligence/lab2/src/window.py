import os
import sys
from os.path import dirname

from PyQt5.QtWidgets import QApplication, QMainWindow, QFileDialog

from dataset import LearningDataSet
from ui.main_window import Ui_MainWindow
from util import read_data


class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setupUi(self)
        self.__initUI()
        self.__accuracyStr = ''
        self.__metricIndex = 0

    def __initUI(self):
        self.loadDatasetButton.clicked.connect(self.__onOpen)
        self.trainButton.clicked.connect(self.__onTrain)
        self.verifyButton.clicked.connect(self.__onVerify)
        self.comboBox.currentIndexChanged.connect(self.__onChooseMetric)
        self.comboBox.setCurrentIndex(0)

        self.successLabel.setVisible(False)
        self.verifyButton.setDisabled(True)
        self.trainButton.setDisabled(True)

    def __onOpen(self):
        filename, _ = QFileDialog.getOpenFileName(self, 'Open dictionary',
                                                  os.path.join(dirname(dirname(__file__)), 'data'),
                                                  'Dictionary Files (*.data)')
        if filename:
            self.__filename = filename
            self.filenameLineEdit.setText(os.path.basename(filename))

            self.successLabel.setVisible(False)
            self.trainButton.setDisabled(False)
            self.verifyButton.setDisabled(True)
            self.accuracyLineEdit.setText('')

    def __onTrain(self):
        number_of_lines = len(open(self.__filename, 'r').readlines())
        learning_set_size = number_of_lines // 3 * 2 + number_of_lines % 3
        control_set_size = number_of_lines // 3
        with open(self.__filename, 'r') as file:
            control_set = read_data(file, control_set_size)
            learning_set = read_data(file, learning_set_size)

        learning_data_set = LearningDataSet(learning_set, self.__metricIndex)

        correctPredictions = 0
        for dataObject in control_set:
            prediction = learning_data_set.prediction(dataObject)
            if dataObject.objectClass == prediction:
                correctPredictions += 1

        accuracy = correctPredictions / control_set_size
        self.__accuracyStr = f"{accuracy * 100:10.4f}%"

        self.successLabel.setVisible(True)
        self.verifyButton.setDisabled(False)

    def __onVerify(self):
        self.accuracyLineEdit.setText(self.__accuracyStr)

    def __onChooseMetric(self, index):
        self.__metricIndex = index
        self.successLabel.setVisible(False)
        self.verifyButton.setDisabled(True)
        self.accuracyLineEdit.setText('')


if __name__ == '__main__':
    app = QApplication(sys.argv)
    form = MainWindow()
    form.show()
    app.exec_()
