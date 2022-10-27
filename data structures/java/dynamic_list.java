import java.util.Scanner;

public class DynamicList {

    public static Scanner sc = new Scanner(System.in);
    public static void main(String [] args) throws Exception{

        List list = new List();

        list.insertEnd(3);
        list.insertBegin(0);
        list.insert(1, 1);
        list.insert(2, 2);
        list.insertEnd(5);

        list.print();

        list.remove(4);

        list.print();

    }

}

    class Cell {

        public int element;
        public Cell next; 
        
        public Cell(){
            this(0);
        }
    
        public Cell(int element) {
          this.element = element;
          this.next = null;
        }
    }

    class List {

        private Cell first;
        private Cell last;
    
        public List() {
            first = new Cell();
            last = first;
        }
    
        public void insertBegin(int x) {
            Cell tmp = new Cell(x);
            tmp.next = first.next;
            first.next = tmp;
            if (first == last) {                 
                last = tmp;
            }
          tmp = null;
        }
    
        public void insertEnd(int x) {
            last.next = new Cell(x);
            last = last.next;
        }
    
        public int removeBegin() throws Exception {

            if (first == last) {
                throw new Exception("Error! List is empty!");
            }
    
            Cell tmp = first;
            first = first.next;
            int resp = first.element;
            tmp.next = null;
            tmp = null;

            return resp;
        }
    

        public int removeEnd() throws Exception {

            if (first == last) {
                throw new Exception("Error! List is empty!");
            } 
    
            Cell i;
            for(i = first; i.next != last; i = i.next);
        
            int resp = last.element; 
            last = i; 
            i = last.next = null;
          
            return resp;
        }
    
       public void insert(int x, int pos) throws Exception {
    
          int size = size();
    
          if(pos < 0 || pos > size){
                throw new Exception("Error! Position (" + pos + " / size = " + size + ") invalid!");
          } else if (pos == 0){
             insertBegin(x);
          } else if (pos == size){
             insertEnd(x);
          } else {
             Cell i = first;
             for(int j = 0; j < pos; j++, i = i.next);
            
             Cell tmp = new Cell(x);
             tmp.next = i.next;
             i.next = tmp;
             tmp = i = null;
          }
       }
    
        public int remove(int pos) throws Exception {

          int resp;
          int size = size();
    
            if (first == last){
                throw new Exception("Error! List is empty!");
    
          } else if(pos < 0 || pos >= size){
                throw new Exception("Error! Position (" + pos + " / size = " + size + ") invalid!");
          } else if (pos == 0){
             resp = removeBegin();
          } else if (pos == size - 1){
             resp = removeEnd();
          } else {
             Cell i = first;
             for(int j = 0; j < pos; j++, i = i.next);
            
             Cell tmp = i.next;
             resp = tmp.element;
             i.next = tmp.next;
             tmp.next = null;
             i = tmp = null;
          }
    
            return resp;
        }
    
        public void print() {

            int position = 0;

            for (Cell i = first.next; i != null; i = i.next) {

                System.out.print("[" +position+ "]" + i.element + " ");
                position++;
            }

            System.out.println();
        }
    
       public int size() {
          int size = 0; 
          for(Cell i = first; i != last; i = i.next, size++);
          return size;
       }

    }