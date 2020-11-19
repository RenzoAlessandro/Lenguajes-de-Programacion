public class Carro implements Rueda, Motor{

    public Carro(){

    }

    public void avanzar(){

        System.out.println("El carro avanza");

    }
    public void detenerse(){
        
        System.out.println("El carro se detiene");

    }

    public void tieneMotor(){
        System.out.println("El carro tiene Motor");
    }
    
}
