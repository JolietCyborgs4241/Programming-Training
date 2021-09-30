public class zeros_to_the_front
{
    public int[] getUpdatedArray(int[] array)
    {
        this.array = array; 
        length = array.length; 
        execute();

        return this.array; 
    }

    private int[] array = {};
    private int length = 0; 

    private void execute()
    {
    	int soup = 0; 
    	int saved = 0;
    	for (int i = 0; i < length; i++)
    	{
    		if (array[i] == 0)
    		{
    			saved = array[soup];
    			array[soup] = 0;
    			array[i] = saved; 
    			soup++;
    		}
    	}
    		
    }
}
