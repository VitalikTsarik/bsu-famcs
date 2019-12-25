import java.awt.List;
import java.io.*;
import java.awt.event.*;
import java.awt.*;
import java.util.*;
import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;

public class MainWindow extends JFrame implements ActionListener
{

	private List list = new List();
    private List list2 = new List();
	private JMenuItem menuItem;

    public MainWindow(String title)
    {
        super(title);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

	    JMenuBar menuBar = new JMenuBar();
	    JMenu menu = new JMenu("File");

        menuItem = new JMenuItem("Open...");
        menuItem.addActionListener(this);
        menu.add(menuItem);
        menuBar.add(menu);
        setJMenuBar(menuBar);

        Box b = new Box(2);

        Container container = this.getContentPane();
        container.setLayout(new BoxLayout(container, BoxLayout.Y_AXIS));
        JPanel jPanel = new JPanel();
	    JLabel label = new JLabel("Security Guards:");
	    jPanel.add(label);

        b.add(jPanel);
        b.add(list);
        b.add(list2);
        container.add(b);

        Box b2 = new Box(2);

        container.add(b2);

        setSize(600, 180);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
       if (e.getSource() == menuItem)
       {
            JFileChooser chooser = new JFileChooser();
            FileNameExtensionFilter filter = new FileNameExtensionFilter("xml files", "xml");
            chooser.setFileFilter(filter);
            File workingDirectory = new File(System.getProperty("user.dir"));
            chooser.setCurrentDirectory(workingDirectory);
            if (chooser.showOpenDialog(this) == JFileChooser.APPROVE_OPTION)
                show(SecurityParser.xmlToWorkers(chooser.getSelectedFile().getName()));
        }
    }

    private void show(ArrayList<Worker> workers)
    {
    	Collections.sort(workers);
	        Map<String, Integer> map = minSalaryByPosition(workers);
            for (Worker worker : workers)
            {
	            list.add(worker.toString());
            }
	        for(Map.Entry<String, Integer> ent: map.entrySet())
	        {
		        list2.add(ent.getKey() + ": " + ent.getValue());
	        }
    }

	private static Map<String, Integer> minSalaryByPosition(ArrayList<Worker> workers) {
		Map<String, Integer> hashMap = new HashMap<>();

		for(Worker w: workers)
		{
			Integer minSalary = hashMap.get(w.getPosition());
			if(minSalary == null || w.getSalary() < minSalary)
				hashMap.put(w.getPosition(), w.getSalary());
		}
		return hashMap;
	}
}
