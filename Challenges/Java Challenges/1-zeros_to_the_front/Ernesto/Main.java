public class Main
{
    static int[][] arrays =
    {
        new int[]{1, 2, 9, 5, 6},
        new int[]{},
        new int[]{},
        new int[]{},
        new int[]{},
        new int[]{},
        new int[]{},
        new int[]{},
        new int[]{},
    };

    static zeros_to_the_front program = new zeros_to_the_front(); 

    static void displayArray(int[] array)
    {
        System.out.print("{ ");

        for(int i = 0; i < array.length; i++)
        {
            if(i != 0 && i != array.length - 1)
            {
                System.out.print(", ");
            }

            System.out.print(array[i]);
        }

        System.out.print(" }"); 
    }

    static int getNumOfZeros(int[] array)
    {
        int num_of_zeros = 0; 

        for(int i = 0; i < array.length; i++)
        {
            if(array[i] == 0)
            {
                num_of_zeros++;
            }
        }

        return num_of_zeros; 
    }

    static void runTest(int[] array, int trial)
    {
        int[] updated_array = new zeros_to_the_front().getUpdatedArray(array); 

        System.out.print("Test " + trial + " -> BEFORE: ");
        displayArray(array); 
        System.out.print("    AFTER: "); 
        displayArray(updated_array);
        System.out.print("    CONCLUSION: "); 

        for(int i = 0; i < getNumOfZeros(updated_array); i++)
        {
            try
            {
                if(updated_array[i] != 0)
                {
                    System.out.println("FAILED \n");
                    return; 
                }
            }

            catch(IndexOutOfBoundsException e){}
        }
        
        System.out.println("SUCCESSFUL \n");
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