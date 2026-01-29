import org.junit.Assert;
import java.util.Random;

public class Athlete {

    private final int dossard;
    private static int numero = 1;
    private boolean temoin;
    private int dernierTemps = 0;
    private Athlete suivant;

    private final static Random r = new Random();

    public Athlete(){
        this.dossard = numero;
        this.temoin = false;
        ++numero;
    }

    public String toString() {
        return Integer.toString(this.dossard);
    }

    public void RendLeTemoin(){

        Assert.assertTrue(this.temoin);

        this.temoin = false;
    }

    public void PrendLeTemoin(){

        Assert.assertFalse(this.temoin);

        this.temoin = true;

    }

    public boolean aLeTemoin(){
        return this.temoin;
    }

    public void PasseLeTemoinA(Athlete A){

        Assert.assertTrue(temoin);
        Assert.assertFalse(A.aLeTemoin());

        this.temoin = false;
        A.PrendLeTemoin();
    }

    public int getDernierTemps() {
        return this.dernierTemps;
    }

    public void court() {
        Assert.assertTrue(this.aLeTemoin());

        this.dernierTemps = r.nextInt(9, 15);

        if(this.suivant == null){
            this.RendLeTemoin();
            return;
        }
        this.PasseLeTemoinA(this.suivant);
    }

    public void setSuivant(Athlete s) {
        Assert.assertNull(s.suivant);
        this.suivant = s;
    }
}
