import org.junit.Assert;
import org.junit.Test;

public class MonTest {
    @Test
    public void monPremierTest(){
        for(int i = 1; i <= 10; i++){
            Athlete athlete = new Athlete();
            Athlete athlete2 = new Athlete();
            Assert.assertEquals(athlete, athlete2);
        }
    }

    @Test
    public void TestTemoin(){
        Athlete a = new Athlete();
        Assert.assertFalse(a.aLeTemoin());
        a.PrendLeTemoin();
        Assert.assertTrue(a.aLeTemoin());
        Athlete a2 = new Athlete();
        Assert.assertFalse(a2.aLeTemoin());
        a.PasseLeTemoinA(a2);
        Assert.assertFalse(a.aLeTemoin());
        Assert.assertTrue(a2.aLeTemoin());
    }

    @Test
    public void TestCourse(){
        Athlete a = new Athlete();
        a.PrendLeTemoin();
        for(int i = 1; i <= 100; i++){
            a.court();
            assert(a.getDernierTemps() <= 14 && a.getDernierTemps() >= 9);
        }
    }
}
