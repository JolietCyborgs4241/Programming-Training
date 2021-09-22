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
        int removed_value = 0, removed_value_index = 0; 
  
        for(int current_index = 0; current_index < length; current_index++)
        {
        	if(array[current_index] == 0)
        	{
        		removed_value = array[removed_value_index];
        		array[removed_value_index] = 0;
        		array[current_index] = removed_value;
        		removed_value_index++; 
        	}
        }
    }
}
