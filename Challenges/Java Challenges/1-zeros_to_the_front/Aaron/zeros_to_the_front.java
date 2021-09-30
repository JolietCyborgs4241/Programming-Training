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
    int saved_num = 0;
    int left_most_index = 0;

    private void execute()
    {		
    	for(int i = 0; i < length; i++) 
    	{
    		if(array[i] == 0)
    		{
    			saved_num = array[left_most_index];
    			array[left_most_index] = array[i];
    			array[i] = saved_num;
    			left_most_index++;
    		}
    		
    	}
    	
    	
    }

}
