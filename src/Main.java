public class Main {
    public static void main(String[] args) {
        Athlete a = new Athlete();
        Athlete b = new Athlete();
        Athlete c = new Athlete();
        Athlete d = new Athlete();
        Athlete e = new Athlete();
        a.setSuivant(b);
        b.setSuivant(c);
        c.setSuivant(d);
        d.setSuivant(e);
        a.PrendLeTemoin();
        a.court();
        b.court();
        c.court();
        d.court();
        e.court();
    }
}