import Series.Exponential;
import Series.Liner;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

public class MainWindow extends JFrame implements ActionListener
{
	public static void main(String[] args)
	{
		new MainWindow("Series");
	}

	private JButton show = new JButton("Show");
	private JButton edit = new JButton("Edit");
	private JTextField input = new JTextField("output.txt", 5);
	private JLabel label = new JLabel("  FileName:");
	private JRadioButton radio1 = new JRadioButton("Liner");
	private JRadioButton radio2 = new JRadioButton("Exponential");
	private JButton save = new JButton("Save");
	private Liner liner = new Liner(3, 10, 5);
	private Exponential exponential = new Exponential(2, 8, 2);

	public MainWindow(String title) throws HeadlessException
	{
		super(title);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		initUi();

		pack();
		this.setVisible(true);
	}

	private void initUi()
	{
		Container container = getContentPane();
		container.setLayout(new GridLayout(4, 3));
		container.add(label);
		container.add(input);
		container.add(save);
		ButtonGroup group = new ButtonGroup();
		group.add(radio1);
		group.add(radio2);
		container.add(radio1);
		radio1.setSelected(true);
		save.addActionListener(this);
		container.add(new JLabel(""));
		container.add(new JLabel(""));
		container.add(radio2);
		container.add(new JLabel(""));
		container.add(new JLabel(""));
		container.add(new JLabel(""));
		show.addActionListener(this);
		container.add(show);
		edit.addActionListener(this);
		container.add(edit);
	}

	public void actionPerformed(ActionEvent e)
	{
		if (e.getSource() == show)
		{

			String title;
			String message;
			if (radio1.isSelected())
			{
				title = radio1.getText();
				message = liner.toString();
			} else
			{
				title = radio2.getText();
				message = exponential.toString();
			}
			JOptionPane.showMessageDialog(this, message, title, JOptionPane.PLAIN_MESSAGE);
		}else if (e.getSource() == save)
		{
			try {
				if (radio1.isSelected())
					liner.saveToFile(input.getText());
				else
					exponential.saveToFile(input.getText());
			} catch (IOException ex) {
				JOptionPane.showMessageDialog(this, ex, "Error!", JOptionPane.PLAIN_MESSAGE);
			}
		} else if (e.getSource() == edit)
			new EditDialog(this, radio1.isSelected() ? liner : exponential);
	}
}
