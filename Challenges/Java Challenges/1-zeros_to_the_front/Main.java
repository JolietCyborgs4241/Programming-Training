public class Main {

  public static void main(String[] args) {
    int a[] = {10,2,1,3,4,5,6,6};
    int temp =0;
    for(int i=0;i<a.length;i++) {
      for(int j=i;j<a.length;j++) {
        if(a[i]>a[j]) {
          temp = a[i];
          a[i] = a[j];
          a[j] = temp;
        }
      }
    }
    for(int i=0;i<a.length;i++) {
      System.out.print(" "+a[i]+" ");
    }
  }
}
	     
	 