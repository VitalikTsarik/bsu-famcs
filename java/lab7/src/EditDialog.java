import Series.*;

import java.awt.event.*;
import java.awt.*;
import javax.swing.*;

public class EditDialog extends JDialog implements ActionListener {
    private JButton ok = new JButton("OK");
	private JTextField inputN = new JTextField();
    private JTextField inputFirst = new JTextField();
	private Series q;

    public EditDialog(JFrame parent, Series q) {
        super(parent);
        setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
        setResizable(false);
        setVisible(true);
        this.q = q;

	    inputN.setText(Integer.toString(q.getN()));
	    inputFirst.setText(Double.toString(q.getFirstElement()));
	    JLabel labelDifferenceOrCommonRatio = new JLabel();
	    JTextField inputDifferenceOrCommonRatio = new JTextField();
	    if (q instanceof Liner)
	    {
		    inputDifferenceOrCommonRatio.setText(Double.toString(((Liner) q).getDifference()));
		    labelDifferenceOrCommonRatio.setText("  Difference:");
		    setTitle("Liner");
	    }
	    else
	    {
		    inputDifferenceOrCommonRatio.setText(Double.toString(((Exponential) q).getCommonRatio()));
		    labelDifferenceOrCommonRatio.setText("  Common Ratio:");
		    setTitle("Exponential");
	    }


        Container container = this.getContentPane();
        container.setLayout(new GridLayout(4, 2));
	    container.add(new JLabel("  n:"));
        inputN.setText(Double.toString(q.getN()));
        container.add(inputN);
	    container.add(new JLabel("  First:"));
        inputFirst.setText(Double.toString(q.getFirstElement()));
        container.add(inputFirst);
        container.add(labelDifferenceOrCommonRatio);
	    inputDifferenceOrCommonRatio.setText(Double.toString(q.getFirstElement()));
        container.add(inputDifferenceOrCommonRatio);
        container.add(new JLabel(""));
        ok.addActionListener(this);
        container.add(ok);
        pack();
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == ok) {
            q.setFirstElement(Double.parseDouble(inputFirst.getText()));
            q.setN((int)Double.parseDouble(inputN.getText()));
            setVisible(false);
        }
    }
}