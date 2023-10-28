package Sorting;

public class shell {

    public static void main(String args[])
    {
        int[] a={9, 8, 3, 56, 5, 6, 4, 1};
        int length=a.length;


     int gap=length/2;
    // System.out.println(gap);
      while(gap>0)
      {
          for(int i=gap;i<length;i++)
          {
              int temp=a[i];
           //   System.out.println((temp));

              int j=i;
           //   System.out.println((j));

              while(j>=gap && a[j-gap]>temp)
              {
               //   System.out.println(a[j]);
                  a[j]=a[j-gap];
                //  System.out.println(a[j]);
                  j=j-gap;

                  a[j]=temp;
               //   System.out.println(a[j]);

              }


          }

          gap=gap/2;


      }
        for(int i=0;i<length;i++)
        {
            System.out.println(a[i]);
        }
    }
}
