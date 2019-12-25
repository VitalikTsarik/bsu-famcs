import java.util.List;
import java.util.ArrayList;

public class BTree<T extends Comparable<T>>
{
	private class Node
	{
		private T data;
		private Node left;
		private Node right;

		public Node(T data)
		{
			this.data = data;
		}
	}

	private Node root;

	public void add(T data)
	{
		root = add(root, data);
	}

	private Node add(Node cur, T data)
	{
		if (cur == null)
			return new Node(data);

		int cmp = data.compareTo(cur.data);
		if (cmp < 0)
			cur.left = add(cur.left, data);
		else if (cmp > 0)
			cur.right = add(cur.right, data);
		else
			cur.data = data;

		return cur;
	}

	public void remove(T item)
	{
		root = remove(root, item);
	}

	private Node remove(Node cur, T item)
	{
		if (cur == null)
			return null;

		int cmp = item.compareTo(cur.data);
		if (cmp < 0)
			cur.left = remove(cur.left, item);
		else if (cmp > 0)
			cur.right = remove(cur.right, item);
		else
		{
			if (cur.left == null)
				return cur.right;
			if (cur.right == null)
				return cur.left;

			Node tmp = cur;
			cur = max(cur.left);
			cur.left = removeMax(tmp.left);
			cur.right = tmp.right;
		}
		return cur;
	}

	private Node max(Node root)
	{
		if (root.right == null)
			return root;
		return max(root.right);
	}

	private Node removeMax(Node root)
	{
		if (root.right == null)
			return root.left;
		root.right = removeMax(root.right);
		return root;
	}

	public boolean find(T data)
	{
		Node cur = root;
		while (cur != null)
		{
			int cmp = data.compareTo(cur.data);
			switch (cmp)
			{
				case -1:
					cur = cur.left;
					break;
				case 1:
					cur = cur.right;
					break;
				case 0:
					return true;
			}
		}
		return false;
	}

	public List<T> preOrder()
	{
		List<T> list = new ArrayList<>();
		preOrder(root, list);
		return list;
	}

	private void preOrder(Node cur, List<T> list)
	{
		if (cur == null)
			return;
		list.add(cur.data);
		preOrder(cur.left, list);
		preOrder(cur.right, list);
	}

	public List<T> postOrder()
	{
		List<T> list = new ArrayList<>();
		postOrder(root, list);
		return list;
	}

	private void postOrder(Node cur, List<T> list)
	{
		if (cur == null)
			return;
		postOrder(cur.left, list);
		postOrder(cur.right, list);
		list.add(cur.data);
	}

	public List<T> inOrder()
	{
		List<T> list = new ArrayList<>();
		inOrder(root, list);
		return list;
	}

	private void inOrder(Node cur, List<T> list)
	{
		if (cur == null)
			return;
		inOrder(cur.left, list);
		list.add(cur.data);
		inOrder(cur.right, list);
	}

	public List<T> Leaves()
	{
		List<T> list = new ArrayList<>();
		Leaves(root, list);
		return list;
	}

	public void Leaves(Node cur, List<T> list)
	{
		if (cur == null)
			return;
		if (cur.left == null && cur.right == null)
			list.add(cur.data);
		Leaves(cur.left, list);
		Leaves(cur.right, list);
	}
}


