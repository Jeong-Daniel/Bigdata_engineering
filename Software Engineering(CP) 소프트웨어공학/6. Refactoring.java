import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class SimpleStat {
	public static final integer Sum_start=0
	public static final integer Product_start=1		
	public static void main(String[] args) {
		Scanner insert_line = new Scanner(System.in);
		System.out.println("Enter integer ( 0 or minus for Exit)");
		List<Integer> ns = new ArrayList<>();
		while (true) {
			int next_line = insert_line.nextInt();
			final boolean Num_isOver_Zero = next_line <= 0;
			if (Num_isOver_Zero)
				break;
			insert_line.add(next_line);
		}
		insert_line.close();
		long sum = Sum_start;
		long product = Product_start;
		for (int add_number : insert_line) {
			sum += add_number;
			product *= add_number;
		}
		System.out.println("Sum: " + sum);
		System.out.println("Product: " + product);
	}
}