import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;

public class Main {

    public static void main(String[] args) {
    	try
	    {
		    Scanner sc = new Scanner(new File("input.txt"));
		    while (sc.hasNextLine())
		    {
			    frequencyTable(sc.nextLine());
		    }
	    }
	    catch (FileNotFoundException  e)
	    {
	    	System.out.println(e);
	    }
    }

    public static void frequencyTable(String str)
    {
		HashMap<Character, Integer> symbols = new HashMap<>();
		for (int i = 0; i < str.length(); ++i)
		{
			char ch = str.charAt(i);
			if (symbols.containsKey(ch))
				symbols.put(ch, symbols.get(ch) + 1);
			else
				symbols.put(ch, 1);
		}
		
		System.out.println("Char | Quantity");
	    symbols.forEach((Character ch, Integer quantity)->
			    {
					System.out.println(String.format("  %s  | %d", ch, quantity));
			    }
	    );
	    System.out.println();
    }
}
