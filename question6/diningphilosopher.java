import java.util.concurrent.Semaphore; 

class diningphilosopher
{

	 static Semaphore [] chopstick = new Semaphore [] {new Semaphore(1),
     new Semaphore(1), new Semaphore(1), new Semaphore(1), new Semaphore(1)};
	


	static class Philosopher extends Thread
	{
		int num;
		int left;
		int right;
		
		Philosopher(int i )
		{
			num=i;
			left=i;
			right =(i+1)%5;
		}
		public void run()
		{
			
			try
			{
				
			chopstick[left].acquire();
			System.out.println("PHILOSOPHER " + num + "HAS PICKED FORK" + left);
			chopstick[right].acquire();
			System.out.println("PHILOSOPHER " + num + "HAS PICKED FORK" +right);
			
			System.out.println("PHILOSPHER " + num + " HAS STARTED EATING ");
			Thread.sleep(1000);
			chopstick[left].release();
			chopstick[right].release();
			System.out.println("PHILSOPHER" + num + " HAS STOPPED EATING");
				
			}catch(InterruptedException e)
			{
				System.out.println("PHILOSOPHER " + num + " HAS BEEN INTERRUPTED");
			}
			

		}		
	
	}
   
	
  public static void main(String args[])
	{
		Philosopher[] p = new Philosopher[] {new Philosopher(0) ,new Philosopher(1) ,new Philosopher(2) ,new Philosopher(3) ,new Philosopher(4) } ;
		Thread t[] =new Thread[5];
		for(int i=0;i<5;++i)
		{
			t[i]=new Thread(p[i]);
		}
		for(int i=0;i<5;++i)
		{
			t[i].start();
		}
	
	}

}


