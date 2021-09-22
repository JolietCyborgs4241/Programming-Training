public class Main
{
    static int[][] arrays =
    {
        new int[]{2, 4, 12, 0, 3, 0, 0, 2, 1},
        new int[]{0, 2, 0, -1, -9, 6, 0, 0, 1},
        new int[]{1, 2, 9, -1, -9, 8, 12, 8, -8},
        new int[]{0, 0, 0, 1, 2, 3, 0, 0, 0},
        new int[]{1, 0, 0, 0, 0, 0, 0, 0, 0},
        new int[]{0, 0, 0, 0, 0, 0, 0, 0, 1},
        new int[]{1, 0, 9, -3, -3, 1, 0, 9, -10},
        new int[]{1, 0,-6, 6, 0, 0, 8, 0, 3},
        new int[]{-1, 9, 0, 7, -13, 0, 8, -2, 0},
    };

    static zeros_to_the_front program = new zeros_to_the_front(); 

    static int getLargestArrayLength(int[][] arrays)
    {
    	int largest_length = 0;
    	
    	for(int i = 0; i < arrays.length; i++)
    	{
    		if(arrays[i].length > largest_length)
    		{
    			largest_length = arrays[i].length; 
    		}
    	}
    	
    	return largest_length; 
    }
    
    static void displayArray(int[] array)
    {
        System.out.print("{ ");

        for(int i = 0; i < array.length; i++)
        {
            if(i != 0 && i != array.length)
            {
                System.out.print(", ");
            }

            System.out.print(array[i]);
        }

        System.out.print(" }"); 
    }
    
    static void runTest(int[] array, int trial)
    {
    	String line_adjustment = ""; //Adjust a printed line based on the lengths of the arrays
    	int[] updated_array = new zeros_to_the_front().getUpdatedArray(array); 

        System.out.print("Test " + trial + " -> BEFORE: ");
        displayArray(array); 
        System.out.print(line_adjustment + "	    AFTER: "); 
        displayArray(updated_array);
        System.out.println("\n");
    }

    public static void main(String[] args)
    {
        System.out.println("\nZEROS TO THE FRONT CHALLENGE: \n ");

        for(int i = 0; i < arrays.length; i++)
        {
            runTest(arrays[i], i);
        }

        System.out.println("TESTING CONCLUDED...");
    }
}
