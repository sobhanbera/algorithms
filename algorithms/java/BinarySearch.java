public class BinarySearch {
	
	public static int recursive(int left, int right, int[] numbers, int find) {
		int l = left;
		int r = right;
		int m = (left + right) / 2;
		
		if (r >= l) {
			if (find == numbers[m]) {
				return m;
			}

			if (find > numbers[m]) {
				l = m + 1;
				return recursive(l, r, numbers, find);
			}

			if (find < numbers[m]) {
				r = m - 1;
				return recursive(l, r, numbers, find);
			}
		}
		
		return -1;
	}
	
	public static int iterative(int[] numbers, int find) {
		int left = 0;
		int right = numbers.length - 1;
		
		while(right >= left) {
			int middle = (left + right) / 2;
			
			if (find == numbers[middle]) {
				return middle;
			} else if (find > numbers[middle]) {
				left = middle + 1;
			} else {
				right = middle - 1;
			}
		}
		
		return -1;
	}
}