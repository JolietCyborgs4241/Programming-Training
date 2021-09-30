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
        // all you need is the array and length of the array to write the programe;
        // these variable are already declared above. 

        // write code here: 
    	int echo = 0;
    	int ghostly = 0;
    	for(int i = 0; i > length ; i++)
    	{
    		if(array[i] == 0)
    		{
    		array[i] =4;
    		array[4] = 0;
    		
    		}
    	}
    }
}
