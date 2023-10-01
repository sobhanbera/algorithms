public class Main {  
        public static void main(String[] args) {  
            Main Obj = new Main();  
            Obj.add(11);  
            Obj.add(22);  
            Obj.add(33);  
            Obj.add(44); 
			Obj.add(55); 
            Obj.print();  
        }  
        public class Node{  
            int element;  
            Node next;  
            public Node(int element) {  
                this.element = element;  
            }  
        }  
          
        public Node head = null;  
        public Node tail = null;  
          
        public void add(int element){  
            Node newEle = new Node(element);  
            if(head == null) {  
                head = newEle;  
                tail = newEle;  
                newEle.next = head;  
            }  
            else {  
                tail.next = newEle;  
                tail = newEle;  
                tail.next = head;  
            }  
        }  
          
        public void print() {  //print function
            Node current = head;  
            if(head == null) {  
                System.out.println("List is empty");  
            }  
            else {  
                System.out.println("Nodes of the circular linked list: ");  
                 do{  
                    System.out.print(" "+ current.element);  
                    current = current.next;  
                }while(current != head);  
                System.out.println();  
            }  
        }  
    }
