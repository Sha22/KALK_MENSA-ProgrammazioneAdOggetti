import java.util.Vector;
import java.lang.*;
class Eccezione extends Exception{
	public String s;
	public double t;
	public Eccezione(String d, double tt) {
		s=d;
		t=tt;
		
	}
	public Eccezione() {
		this("errore", 0);
	}
	public String mostra_errore() {
		return s;
	}
	
}
abstract class Cibo{
	private int quant;
	public Cibo(int q) {quant=q;}
	public Cibo() {this(1);}
	 abstract public double get_prezzo();
	 public void setquantita(int i) {
		 quant=i;
	 }
	 public int getquan() {
		 return quant;
	 }
	 public void operator_per(int i){
		 setquantita(i);
	 }
	 //clone da vede 	 
}

class Primo extends Cibo{
	private static double prezzo_primo=5.0;
	public Primo(int i) {super(i);}	
	public Primo() {super();}
	public double get_prezzo() {
		return prezzo_primo;
	}
}
class Secondo extends Cibo{
	private static double prezzo_secondo=6.0;
	public Secondo(int i) {super(i);}
	public Secondo() {super();}	
	public double get_prezzo() {
		return prezzo_secondo;
	}
}
class Contorno extends Cibo{
	private static double prezzo_contorno=3.0;
	public Contorno(int i) {super(i);}
	public Contorno() {super();}	
	public double get_prezzo() {
		return prezzo_contorno;
	}
}
abstract class Persona{
	private String nome;
	private String cognome;
	protected Vector<Cibo> v; 
	public Persona(String n,String c) {nome=n; cognome=c; v=new Vector<Cibo>();}
	public Persona() {this("","");}
	public String getName() {
		return nome;
	}
	public String getCognome() {
		return cognome;
	}
	abstract public double Totale() throws Eccezione;
	abstract public void operator_plus(Cibo c) throws Eccezione;
	public void operator_minus(Cibo c) throws ClassNotFoundException {
		for (int i=0; i<v.size(); i++) {
			String ss=v.get(i).getClass().getName();
			if(Class.forName(ss).isInstance(c)) {
				if(c.getquan()>=v.get(i).getquan()) {
					v.remove(i);
				}
				else {
					v.get(i).setquantita(v.get(i).getquan()-c.getquan());
				}
			}
		}
	}
	public String stampa_scontrino(double t) {
		return "Mensa Sha-Giu Padova \n"+"Nome:"+this.nome+"\n"+"Cognome:"
				+this.cognome+"\n"+"Importo totale: "+t+"euro \n";
	}
	public void reset_v() {
		v.clear();
	}
}

abstract class Convenzionato extends Persona{
	private double soldi_nella_carta;
	public Convenzionato(String n, String c, double d){
		super(n,c);
		soldi_nella_carta=d;
	}
	public Convenzionato() {this("","",0);}
	public double get_soldinellacarta() {
		return soldi_nella_carta;
	}
	public void set_soldinellacarta(double d) {
		soldi_nella_carta+=d;
	}
	public void operator_plus(Cibo c) throws Eccezione{
		if(c.getquan()>1)
			throw new Eccezione("PUOI PRENDERNE SOLO UNO", 0);
		else
			v.add(c);
	}
	public String stampa_scontrino(double d) {
		return super.stampa_scontrino(d)+"Nella carta rimangono: "
	+this.get_soldinellacarta()+"euro \n";
	}
}
class Studente extends Convenzionato {
	private boolean borsa_di_studio;
	private static double sconto=50;
	public Studente(String n, String c, double cc, boolean b) {
		super(n,c,cc); borsa_di_studio=b;
	}
	public Studente() {this("","",0,false);}
	public boolean getBorsaStudio() {
		return borsa_di_studio;
	}
	public double Totale() throws Eccezione  {
		double tot=0;
		for(int i=0; i<v.size(); i++) {
			tot+=v.get(i).get_prezzo();
		}
		if(borsa_di_studio) {
			return 0;
		}
		this.set_soldinellacarta(-(tot-(tot*sconto/100)));
		if(this.get_soldinellacarta()<0)
			throw new Eccezione("Senza soldi \n",tot-(tot*sconto/100));
		return tot-(tot*sconto/100);
		
	}
	public String stampa_scontrino(double t) {
		if(borsa_di_studio)
			return super.stampa_scontrino(t)+"Borsa di studio \n";
		else
			return super.stampa_scontrino(t);
	}
	
}
class Lavoratore extends Convenzionato{
	private static double sconto=30;
	public Lavoratore(String n, String c, double d) {
		super(n,c,d);
	}
	public double Totale() throws Eccezione {
		double tot=0;
		for(int i=0; i<v.size(); i++) {
			tot+=v.get(i).get_prezzo();
		}
		this.set_soldinellacarta(-(tot-(tot*sconto/100)));
		if(this.get_soldinellacarta()<0)
			throw new Eccezione("Senza soldi \n",tot-(tot*sconto/100));
		return tot-(tot*sconto/100);
	}
}

class NonConvenzionato extends Persona{
	public double Totale(){
		double tot=0;
		for(int i=0; i<v.size(); i++) {
			tot+=v.get(i).get_prezzo();
		}
		return tot;
	}
	public void operator_plus(Cibo c) {
		v.add(c);
	}
	public String stampa_scontrino(double d) {
		return super.stampa_scontrino(d);
	}
}
class NonConvConBuono extends NonConvenzionato{
	private int buoni;
	public NonConvConBuono(int i) {
		super(); buoni=i;
	}
	public NonConvConBuono() {this(0);}
	public double Totale() {
		double tot=0;
		for(int i=0; i<v.size(); i++) {
			if(v.get(i).getquan()>buoni) {
				int diff=v.get(i).getquan()-buoni;
				v.get(i).setquantita(diff);
				tot+=v.get(i).get_prezzo();
			}			
		}
		return tot;
	}
	public String stampa_scontrino(double t) {
		return super.stampa_scontrino(t)+"Numero Buoni Utilizzati: "+
	             this.buoni+"\n";
	}
}

public class Use {
		public static void main(String args[]) throws Eccezione {			
			Cibo p=new Primo();
			Cibo s=new Secondo();
			Cibo c=new Contorno();
			
			Persona sh=new Studente("Sha","Della",40,false);
			Persona g=new Studente("Giu","Alba",0,true);			
			Persona nc=new NonConvenzionato();
			Persona nccb=new NonConvConBuono(2);
			Persona l=new Lavoratore("Mario","Rossi",2);
			//sh prende primo secondo e contorno
			try {	
			sh.operator_plus(p);
			sh.operator_plus(s);
			sh.operator_plus(c);
			sh.operator_minus(p);
			//g prende primo e contorno e cancella il primo
			g.operator_plus(p);
			g.operator_plus(c);
			//nc prende primo secondo e controno
			nc.operator_plus(p);
			nc.operator_plus(s);
			nc.operator_plus(c);
			//nccb usa due buoni e prende 3 primi e 3 contorni
			Cibo pp=new Primo(3);
			Cibo cc=new Contorno(3);
			nccb.operator_plus(pp);
			nccb.operator_plus(cc);
			//l prende primo controno
			l.operator_plus(p);
			l.operator_plus(c);
					
			System.out.print(sh.stampa_scontrino(sh.Totale())+"\n");
			/**tot=5+6+3 con lo sconto del 50% risulta 7-2.5 quindi 4.5**/
			System.out.print(g.stampa_scontrino(g.Totale())+"\n");
			/**tot=0 poiche ha la borsa di studio**/
			System.out.print(nc.stampa_scontrino(nc.Totale())+"\n");
			/**tot=14**/
			System.out.print(nccb.stampa_scontrino(nccb.Totale())+"\n");
			/**il tot e 8 poiche uno non ha< il buono**/
			System.out.print(l.stampa_scontrino(l.Totale())+"\n");
			/**non ha abbastanza soldi nella carta; va in finally e continua con altri 				esempi**/
			
			}
			catch(Eccezione e){
				System.out.print(e.mostra_errore());
		    }
			catch (ClassNotFoundException e) {
				
			}
			finally {
				
			}
			
				
			
			
			
		}
}
