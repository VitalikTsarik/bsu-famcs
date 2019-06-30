import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class MainWindow extends JFrame {
    public MainWindow(String title) {
        super(title);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

	    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

	    JTabbedPane tabbedPane = new JTabbedPane();
	    tabbedPane.addTab("Task 1", new Card1());
	    tabbedPane.setMnemonicAt(0, KeyEvent.VK_1);
		tabbedPane.addTab("Task 2", new Card2());
		tabbedPane.setMnemonicAt(1, KeyEvent.VK_2);

	    add(tabbedPane);

	    setSize(500, 600);
	    setVisible(true);
    }

    class Card1 extends JPanel
    {
	    public Card1()
	    {
		    setLayout(new BorderLayout());
		    JPanel central = new JPanel();
		    central.setLayout(new BorderLayout());

		    JButton right = new JButton(new ImageIcon("img/right_arrow.png"));
		    central.add(right, BorderLayout.NORTH);
		    JButton left = new JButton(new ImageIcon("img/left_arrow.png"));
		    central.add(left, BorderLayout.SOUTH);
		    add(central, BorderLayout.CENTER);

		    final String[] DATA1 = { "cake", "braid", "winner", "possible", "compartment",
				    "refrigerator", "judicial", "page", "wolf" };

		    final String[] DATA2 = {"ton", "abnormal", "evaluate", "deter", "ministry", "view"};

		    DefaultListModel<String> leftListModel = new DefaultListModel<>();
		    JList<String> leftList = new JList<>(leftListModel);
		    leftList.setFont(new Font(Font.SANS_SERIF,  Font.PLAIN, 16));
		    DefaultListModel<String> rightListModel = new DefaultListModel<>();
		    JList<String> rightList = new JList<>(rightListModel);
		    rightList.setFont(new Font(Font.SANS_SERIF,  Font.PLAIN, 16));

		    for (String el : DATA1)
			    leftListModel.addElement(el);

		    for (String el : DATA2)
			    rightListModel.addElement(el);

		    add(leftList, BorderLayout.WEST);
		    add(new JScrollPane(leftList, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED, JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED), BorderLayout.WEST);
		    add(rightList, BorderLayout.EAST);
		    add(new JScrollPane(rightList, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED, JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED), BorderLayout.EAST);

		    right.addActionListener(e -> {
			    if (!leftList.isSelectionEmpty()) {
				    rightListModel.addElement(leftList.getSelectedValue());
				    leftListModel.remove(leftList.getSelectedIndex());
				    if (!leftListModel.isEmpty())
					    leftList.setSelectedIndex(0);
			    }
		    });
		    left.addActionListener(e -> {
			    if (!rightList.isSelectionEmpty()) {
				    leftListModel.addElement(rightList.getSelectedValue());
				    rightListModel.remove(rightList.getSelectedIndex());
				    if (!rightListModel.isEmpty())
					    rightList.setSelectedIndex(0);
			    }
		    });

	    }
    }

	class Card2 extends JPanel {
		public Card2() {
			Box box = new Box(1);
			ButtonGroup group = new ButtonGroup();

			for (int i = 0; i < 3; i++) {
				JRadioButton temp = new JRadioButton(new ImageIcon("img/grey.png"));
				temp.setPressedIcon(new ImageIcon("img/green.png"));
				temp.setRolloverIcon(new ImageIcon("img/yellow.png"));
				temp.setSelectedIcon(new ImageIcon("img/red.png"));
				group.add(temp);
				box.add(temp);
			}
			add(box);
		}
	}
}
