import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.image.BufferedImage;
import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class MainFrame extends JFrame
{
    public MainFrame(String s)
    {
        super(s);

        initUi();

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }

    private void initUi()
    {
	    Container content = getContentPane();
	    DrawPanel drawPanel = new DrawPanel(this, 500, 500);
	    JScrollPane pane = new JScrollPane(drawPanel);
	    pane.setSize(300, 300);
	    content.add(pane, BorderLayout.CENTER);

	    JPanel p = new JPanel();
	    content.add(p, BorderLayout.SOUTH);

	    JButton b1 = new JButton("Red");
	    p.add(b1);
	    b1.addActionListener(drawPanel);

	    JButton b2 = new JButton("Green");
	    p.add(b2);
	    b2.addActionListener(drawPanel);

	    JButton b3 = new JButton("Blue");
	    p.add(b3);
	    b3.addActionListener(drawPanel);

	    JButton b4 = new JButton("Black");
	    p.add(b4);
	    b4.addActionListener(drawPanel);

	    JButton b5 = new JButton("Clear");
	    p.add(b5);
	    b5.addActionListener(drawPanel);

	    initMenu(drawPanel);
    }

    private void initMenu(DrawPanel drawPanel)
    {
	    JMenuBar menu = new JMenuBar();

	    JMenu menuFile = new JMenu("File");

	    JMenuItem menuOpenTXT = new JMenuItem(new AbstractAction("Open...") {
	    	@Override
		    public void actionPerformed(ActionEvent e)
		    {
		    	Scanner sc = null;
			    try
			    {
				    sc = new Scanner(new FileReader(ChooseFile(FileMod.OPEN, FileFormat.TXT)));
				    ArrayList<Line> lines = new ArrayList<>();
				    while (sc.hasNext())
				    {
					    Line line = new Line();
					    lines.add(line);
					    line.setColor(new Color(sc.nextInt(), sc.nextInt(), sc.nextInt()));
					    int size = sc.nextInt();
					    for (int i = 0; i < size; i++)
						    line.addPoint(new Point(sc.nextInt(), sc.nextInt()));
				    }
				    drawPanel.setLines(lines);
				    repaint();
			    } catch (FileNotFoundException ex)
			    {
				    ex.printStackTrace();
			    }
			    catch (NullPointerException ex)
			    {
			    }
			    finally
			    {
			    	if (sc != null)
			    		sc.close();
			    }
		    }
	    });


	    JMenuItem menuSaveAsPng = new JMenuItem(new AbstractAction("Save as PNG..."){
		    @Override
		    public void actionPerformed(ActionEvent e)
		    {
			    BufferedImage im = new BufferedImage(drawPanel.getWidth(), drawPanel.getHeight(), BufferedImage.TYPE_INT_RGB);
			    drawPanel.paint(im.getGraphics());
			    try
			    {
			    	ImageIO.write(im, "png", ChooseFile(FileMod.SAVE, FileFormat.PNG));
			    } catch (IOException ex)
			    {
				    JOptionPane.showMessageDialog(null, ex, "Error!", JOptionPane.PLAIN_MESSAGE);
			    } catch (NullPointerException ex) {}

		    }
	    });

	    JMenuItem menuSaveAsTxt = new JMenuItem(new AbstractAction("Save as TXT..."){
		    @Override
		    public void actionPerformed(ActionEvent e)
		    {
			    PrintWriter pr = null;
			    try
			    {
			    	pr = new PrintWriter(ChooseFile(FileMod.SAVE, FileFormat.TXT));
				    for (Line line : drawPanel.getLines())
				    {
					    ArrayList<Point> points = line.getPoints();
					    Color color = line.getColor();
					    pr.write(color.getRed() + " " + color.getGreen() + " " + color.getBlue() + " " + points.size() + " ");
					    for (Point p : points)
					    {
						    pr.write( p.x + " " +  p.y + " ");
					    }
				    }
			    } catch (IOException ex) {
				    JOptionPane.showMessageDialog(null, ex, "Error!", JOptionPane.PLAIN_MESSAGE);
			    } catch (NullPointerException ex) {
			    } finally {
				    if (pr != null)
					    pr.close();
			    }
		    }
	    });

	    JMenuItem menuExit = new JMenuItem(new AbstractAction("Exit") {
		    @Override
		    public void actionPerformed(ActionEvent e)
		    {
			    System.exit(0);
		    }
	    });

	    setJMenuBar(menu);

	    menu.add(menuFile);

	    menuFile.add(menuOpenTXT);
	    menuFile.add(menuSaveAsPng);
	    menuFile.add(menuSaveAsTxt);
	    menuFile.addSeparator();
	    menuFile.add(menuExit);
    }

    private enum FileMod{OPEN, SAVE}
    private enum FileFormat{PNG, TXT}

	private File ChooseFile(FileMod fileMod, FileFormat fileFormat)
	{
		JFileChooser fileChooser = new JFileChooser();
		File workingDirectory = new File(System.getProperty("user.dir"));
		fileChooser.setCurrentDirectory(workingDirectory);
		fileChooser.setAcceptAllFileFilterUsed(false);

		if (fileFormat == FileFormat.PNG)
		{
			fileChooser.setFileFilter(new FileNameExtensionFilter("PNG images (.png)", "png"));
		}
		else
		{
			fileChooser.setFileFilter(new FileNameExtensionFilter("Text files (.txt)", "txt"));
		}

		if (fileMod == FileMod.OPEN)
		{
			if (fileChooser.showOpenDialog(this) == JFileChooser.APPROVE_OPTION)
				return fileChooser.getSelectedFile();
			else
				return null;
		} else
			{
			if (fileChooser.showSaveDialog(this) == JFileChooser.APPROVE_OPTION)
				return fileChooser.getSelectedFile();
			else
				return null;
			}
	}

    public static void main(String[] args)
    {
        new MainFrame("Painting");
    }
}
