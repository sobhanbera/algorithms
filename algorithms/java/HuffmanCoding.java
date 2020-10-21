import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class HuffmanCoding {

    	protected static Map<Character, String> result;

    	static class Node implements Comparable<Node> {
		Node left;
		Node right;
		char data;
		int count;
        
        	public Node(char data, int count, Node left, Node right) {
            		this.data = data;
			this.count = count;
			this.left = left;
			this.right = right;
        	}
        
        	@Override
        	public int compareTo(Node node) {
            		return this.count < node.count ? -1 : 1;
        	}
    	}
	
	public static void main (String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        	System.out.print("\nEnter the string to be encoded: ");
        	String message = reader.readLine().trim();
        	reader.close();

		Map<Character, Integer> frequencies = new HashMap<>();
		for (char character : message.toCharArray())
		    	frequencies.put(character, frequencies.getOrDefault(character, 0) + 1);

		PriorityQueue<Node> queue = new PriorityQueue<>(frequencies.size());
		for (Map.Entry<Character, Integer> pair : frequencies.entrySet())
		    	queue.add(new Node(pair.getKey(), pair.getValue(), null, null));

		while (queue.size() > 1) {
		    	Node left = queue.poll();
		    	Node right = queue.poll();
		    	queue.add(new Node('$', left.count + right.count, left, right));
		}

		result = new HashMap<>();
		preOrder(queue.poll(), "");

		System.out.println("Encodings for each character:");
		for (Map.Entry<Character, String> pair : result.entrySet())
		    	System.out.println(pair.getKey() + ": " + pair.getValue());

		StringBuilder answer = new StringBuilder("");
		for (char character : message.toCharArray())
		    	answer.append(result.get(character));

		System.out.println("\nThe encoded message is: " + answer);
	}
	
	private static void preOrder(Node root, String prefix) {
	    	if (root != null) {
	        	if (root.data != '$') {
	            		result.put(root.data, prefix);
	            		return;
	        	}
	        	preOrder(root.left, prefix + "0");
            		preOrder(root.right, prefix + "1");
	    	}
	}
}
