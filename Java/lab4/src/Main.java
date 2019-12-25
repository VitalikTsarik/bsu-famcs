import java.util.List;
public class Main
{
    public static void main(String[] args)
    {
    	System.out.println("Integer parameterization: ");
		BTree<Integer> integerBTree = new BTree<>();

	    System.out.print("Adding order: 4 10 6 2 8 5 1 3 9 7");
	    integerBTree.add(4);
	    integerBTree.add(10);
	    integerBTree.add(6);
	    integerBTree.add(2);
	    integerBTree.add(8);
	    integerBTree.add(5);
	    integerBTree.add(1);
	    integerBTree.add(3);
	    integerBTree.add(9);
	    integerBTree.add(7);
	    System.out.println();

	    System.out.print("Pre-Order:    ");
	    List<Integer> preOrder = integerBTree.preOrder();
	    for (int val : preOrder)
		    System.out.print(val + " ");
	    System.out.println();

	    System.out.print("Post-Order:   ");
	    List<Integer> postOrder = integerBTree.preOrder();
	    for (int val : postOrder)
		    System.out.print(val + " ");
	    System.out.println();

	    System.out.print("In-Order:     ");
	    List<Integer> inOrder = integerBTree.inOrder();
	    for (int val : inOrder)
		    System.out.print(val + " ");
	    System.out.println();

	    System.out.print("Sum of leaves: ");
	    List<Integer> leaves = integerBTree.Leaves();
	    int sumOfLeaves = 0;
	    for (int leaf : leaves)
		    sumOfLeaves += leaf;
	    System.out.println(sumOfLeaves);
	    System.out.println("\n");

	    integerBTree.remove(6);
	    System.out.println("After removing: ");

	    System.out.print("Pre-Order:    ");
	    preOrder = integerBTree.preOrder();
	    for (int val : preOrder)
		    System.out.print(val + " ");
	    System.out.println();

	    System.out.print("Post-Order:   ");
	    postOrder = integerBTree.preOrder();
	    for (int val : postOrder)
		    System.out.print(val + " ");
	    System.out.println();

	    System.out.print("In-Order:     ");
	    inOrder = integerBTree.inOrder();
	    for (int val : inOrder)
		    System.out.print(val + " ");
	    System.out.println();

	    System.out.print("Sum of leaves: ");
	    leaves = integerBTree.Leaves();
	    sumOfLeaves = 0;
	    for (int leaf : leaves)
	    	sumOfLeaves += leaf;
	    System.out.println(sumOfLeaves);
	    System.out.println("\n");


	    System.out.println("Class \"Person\" parameterization: ");
	    BTree<Person> personBTree = new BTree<>();

	    System.out.print("Adding order: F B A D C E G I H");
	    personBTree.add(new Person("F", 1));
	    personBTree.add(new Person("B", 2));
	    personBTree.add(new Person("A", 3));
	    personBTree.add(new Person("D", 4));
	    personBTree.add(new Person("C", 5));
	    personBTree.add(new Person("E", 6));
	    personBTree.add(new Person("G", 7));
	    personBTree.add(new Person("I", 8));
	    personBTree.add(new Person("H", 9));
	    System.out.println();

	    System.out.print("Pre-Order:    ");
	    List<Person> personPreOrder = personBTree.preOrder();
	    for (Person p : personPreOrder)
		    System.out.print(p);
	    System.out.println();

	    System.out.print("Post-Order:   ");
	    List<Person> personPostOrder = personBTree.postOrder();
	    for (Person p : personPostOrder)
		    System.out.print(p);
	    System.out.println();

	    System.out.print("In-Order:     ");
	    List<Person> personInOrder = personBTree.inOrder();
	    for (Person p : personInOrder)
		    System.out.print(p);
	    System.out.println();
    }

}
