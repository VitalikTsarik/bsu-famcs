import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.ActionEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.util.ArrayList;

public class DrawPanel extends JPanel implements ActionListener, MouseListener, MouseMotionListener
{
	private int w, h;
	private JFrame f;
	private Color currColor = Color.BLACK;
    private ArrayList<Line> lines = new ArrayList<>();
    private Line curLine;

    public DrawPanel(JFrame frame, int width, int height)
    {
        f = frame;
        w = width;
        h = height;
        enableEvents(AWTEvent.MOUSE_EVENT_MASK | AWTEvent.MOUSE_MOTION_EVENT_MASK);
        addMouseListener(this);
        addMouseMotionListener(this);
    }

    public void mouseReleased(MouseEvent me) {}
    public void mouseClicked(MouseEvent me) {}
    public void mouseMoved(MouseEvent me) {}
    public void mouseEntered(MouseEvent me) {}
    public void mouseExited(MouseEvent me) {}
    public void mousePressed(MouseEvent me)
    {
        if((me.getModifiersEx() & MouseEvent.BUTTON1_DOWN_MASK) == 0)
            return;
	    curLine = new Line(currColor);
	    lines.add(curLine);
	    curLine.addPoint(me.getPoint());
    }
    public void mouseDragged(MouseEvent me)
    {
        if((me.getModifiersEx() & MouseEvent.BUTTON1_DOWN_MASK) == 0)
            return;
        curLine.addPoint(me.getPoint());
	    repaint();
    }

    public Dimension getPreferredSize()
    {
        return new Dimension(w, h);
    }

    public void actionPerformed(ActionEvent e)
    {
        String s = e.getActionCommand();
        switch (s)
        {
            case "Clear":
            	lines.clear();
                repaint();
                break;
            case "Red":
                currColor = Color.RED;
                break;
            case "Blue":
                currColor = Color.BLUE;
                break;
            case "Green":
                currColor = Color.GREEN;
                break;
            case "Black":
                currColor = Color.BLACK;
                break;
        }
    }

	@Override
	protected void paintComponent(Graphics g) {
		super.paintComponent(g);
		for (Line line : lines) {
			line.draw(g);
		}
	}
	public ArrayList<Line> getLines()
	{
		return lines;
	}

	public void setLines(ArrayList<Line> lines)
	{
		this.lines = lines;
	}
}

