import java.io.File;
import java.util.ArrayList;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.DocumentBuilder;
import org.w3c.dom.Document;
import org.w3c.dom.NodeList;
import org.w3c.dom.Node;
import org.w3c.dom.Element;

public class SecurityParser
{
	public static ArrayList<Worker> xmlToWorkers(String fileName)
	{
		ArrayList<Worker> list = new ArrayList<>();
		try
		{

			File fXmlFile = new File(fileName);
			DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
			DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
			Document doc = dBuilder.parse(fXmlFile);

			doc.getDocumentElement().normalize();

			NodeList nList = doc.getElementsByTagName("security_guard");

			for (int i = 0; i < nList.getLength(); i++)
			{

				Node nNode = nList.item(i);

				if (nNode.getNodeType() == Node.ELEMENT_NODE)
				{

					Element eElement = (Element) nNode;
					SecurityGuard securityGuard = new SecurityGuard(
							eElement.getElementsByTagName("name").item(0).getTextContent(),
							eElement.getElementsByTagName("position").item(0).getTextContent(),
							Integer.parseInt(eElement.getElementsByTagName("salary").item(0).getTextContent()),
							eElement.getElementsByTagName("object_name").item(0).getTextContent()
					);
					list.add(securityGuard);
				}
			}
		} catch (Exception e)
		{
			e.printStackTrace();
		}
		return list;
	}
}
