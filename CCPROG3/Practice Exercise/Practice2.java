public class Practice2{
	public static void main (String[] args){
		String  s1 = "Hello",
        s2 = "Hello",
        s3 = s1,
        s4 = new String("Hello"),
        s5 = new String("Hello");

		/**
		 *  == operator compares two variables of primitive data types but
		 * can also be used in objects (compares memory locations)
		 * */

		System.out.println("Usage of ==");
		System.out.println("s1 == s2 -> " + String.valueOf(s1 == s2));
		System.out.println("s2 == s3 -> " + String.valueOf(s2 == s3));
		System.out.println("s1 == s4 -> " + String.valueOf(s1 == s4));
		System.out.println("s4 == s5 -> " + String.valueOf(s4 == s5));

		/**
		 * equals() method can only be used on objects, compares memory
		 * location first then character by character
		 */

		System.out.println("Usage of equals()");
		System.out.println("s1 == s2 -> " + s1.equals(s2));
		System.out.println("s2 == s3 -> " + s2.equals(s3));
		System.out.println("s1 == s4 -> " + s1.equals(s4));
		System.out.println("s4 == s5 -> " + s4.equals(s5));
	}
}
