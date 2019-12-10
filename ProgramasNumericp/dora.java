
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

/**
 *
 * @author josue
 */
public class dora {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        int fil, col, tamanio;
        
        Scanner reader = new Scanner(System.in);
        fil = 1;
        col = 1;
        
        ArrayList<Integer> numeros = new ArrayList<>();
        
        
        ArrayList<Integer> vector = new ArrayList<>();
        ArrayList<Integer> filaa = new ArrayList<>();
        
        
        
        while(fil != 0 && col != 0){
            fil=reader.nextInt();
            col=reader.nextInt();
            
            numeros.add(fil);
            numeros.add(col);
            
        }
        
        reader.close();
        
        vector = (ArrayList) numeros.clone();
        Collections.sort(vector);
        
        tamanio = vector.get(vector.size()-1);
        
        vector = new ArrayList<>();
        
        filaa.add(1);
        filaa.add(2);
        
        int n = 1;
        
        for(int i = 2; i <= tamanio; i++){
            
            if(i%2 ==0 ){
               filaa.add(filaa.get(i-1)+4*n); 
               n++;
            }else{
                filaa.add(filaa.get(i-1)+1); 
            }
            
            
            
        }
        n=0;
        tamanio = numeros.size()-2;

        for (int i = 0; i < tamanio;i++){
            vector.add(funcioncita(numeros.get(i), numeros.get(i + 1),filaa));
            i++;
            
        }
        
        vector.forEach(a->{
            System.out.println(a);
        });
        
        
        
    }
    
    
    public static int funcioncita(int i, int j,ArrayList<Integer> filaa){
        //System.out.println("x = "+i +"  "+j+"\n");
        if ( i == 1) {
            return filaa.get(j-1);
        }
        
        int newI = i + j - 2;
        
        //System.out.println(newI + " j: "+j);
        if(newI%2 ==0 ){
            //System.out.println("par");
               return (filaa.get(newI) - i + 1); 
            }else{
            //System.out.println("impar");
                return (filaa.get(newI) + i - 1); 
            }
        
       
    }
}
