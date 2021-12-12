import java.util.ArrayList;
import java.util.TreeSet;
import java.util.Vector;

public class GestionCollections {
    static TreeSet pairs(ArrayList votrePrenom) {
        TreeSet tr = new TreeSet<>();
        for (Object ob : votrePrenom
        ) {
            if (ob instanceof Integer) {
                Integer entier = (Integer) ob;
                if (entier.intValue() % 2 == 0) tr.add(entier);

            }
        }

        return tr;
    }
    static double frequence(Vector votreNom,double x){
        double frequence = 0;
        for (Object obj:votreNom
             ) {
            if(obj instanceof  Double){
                Double valeur = (Double)obj;
                if(valeur.doubleValue()==x)
                    frequence++;
            }

        }
        return  frequence/votreNom.size();
    }
}
 class Etudiant {

    static final int MR = 8;
    static final int MAD = 10;
    int numE;
    String nomE;
    double moy;

    public Etudiant(int numE, String nomE) {
        this.numE = numE;
        this.nomE = nomE;
    }

    public boolean annee_reserve() {
        if (this.moy <= MAD && this.moy >= MR && !(this instanceof Redoublant)) return true;
        return false;
    }

     class Hajar laktioui {

         int nbE;
         Etudiant[] tabE;

         public void jurry(int n) {
             if (n > tabE.length - 1) System.out.println("Non existant");
             else {
                 if (tabE[n].moy > Etudiant.MAD) System.out.println("Réussi");
                 else if (tabE[n].annee_reserve()) System.out.println("Redouble");
                 else System.out.println("Réorienté");
             }
         }
     }
}