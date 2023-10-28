import java.util.Arrays;

public class InsertionSort {

    //Função para o Insertion Sort
    public static void sort(int[] vetor) {
        int aux, j;
        //Laço de repetição para percorrer a lista
        for (int i = 1; i < vetor.length; i++) {
            //Auxiliar para melhor leitura
            aux = vetor[i];
            //Indice do vetor
            j = i - 1;

            //Enquanto as 2 opções forem Verdadeiras
            while(j >= 0 && aux < vetor[j]) {
                //O num q estava na posição j+1 vai ocupar a posição j
                vetor[j+1] = vetor[j];
                //Caso o aux precise andar mais de uma casa para esquerda
                j--;
            }
            vetor[j+1] = aux;
        }
    }


    //Função Principal
    public static void main(String[] args) {
        //Criação lista 0  1  2  3  4
        int[] vetor = { 3, 4, 1, 2, 5 };

        //Função para ordenar a lista
        sort(vetor);

        //Imprimindo a lista Ordenada
        System.out.println(Arrays.toString(vetor));
    }
}
