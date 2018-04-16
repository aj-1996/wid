import java.util.*;
import java.math.*;
/**
 * 
 */

/**
 * @author Aniket Jire
 *
 */
public class shatr {
	static int[] H = {0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0};
    static int[] K = {0x5A827999, 0x6ED9EBA1, 0x8F1BBCDC, 0xCA62C1D6};
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		System.out.println("Enter the text");
		String password = in.nextLine();
		byte[] buffer = password.getBytes();
		String Hash= SHA(buffer);
		
	}

	private static byte[] padTheMessage(byte[] data)
	{
		int origLength=data.length;
		int thePadlength = 64-origLength-8;
		
		byte[] thePad = new byte[thePadlength];
		thePad[0]=(byte)0x80;
		
		byte[] theLength = new byte[8];
		int lengthInBits = origLength*8;
		String val = Integer.toBinaryString(lengthInBits);
		
		byte[] bval = new BigInteger(val,2).toByteArray();
		int temp=bval.length;
		for(int k=8-temp,j=0;k<8;j++,k++)
		{
			theLength[k]=bval[j];
		}
		temp=theLength.length;
		byte[] output = new byte[origLength+thePadlength+8];
		int i,p;
		temp=data.length;
		for(i=0,p=0;p<temp;i++,p++)
			output[i]=data[p];
		temp=data.length+thePad.length;
		for(i=0,p=0;p<temp;i++,p++)
			output[i]=thePad[p];
		temp=output.length;
		for(i=0,p=0;p<temp;i++,p++)
			output[i]=theLength[p];
		
		temp=output.length;
		return output;
		
	}

	
	private static String SHA(byte[] buffer)
	{
		byte[] paddedMsg = padTheMessage(buffer);
		int[] W = new int[80];
		
		for(int outer=0;outer<16;outer++)
		{
			int temp=0;
			for(int inner=0;inner<4;inner++)
			{
				temp= (paddedMsg[outer*4+inner] & 0x000000FF )<<(24-inner*8);
				W[outer]=W[outer]|temp;
			}
		}
		
		for(int j=16;j<80;j++)
		{
			W[j]= rotateleft(W[j-3]^W[j-8]^W[j-14]^W[j-16],1);
		}
		
		int A,B,C,D,E,F,temp;
		
		A=H[0];
		B=H[1];
		C=H[2];
		D=H[3];
		E=H[4];
		
		for(int j=0;j<20;j++)
		{
			F= (B&C) | ((~B)&D);
			temp = rotateleft(A,5)+F+E+K[0]+W[j];
			E=D;
			D=C;
			C=rotateleft(B,30);
			B=A;
			A=temp;
		}
		
		for(int j=20;j<40;j++)
		{
			F= B^C^D;
			temp = rotateleft(A,5)+F+E+K[1]+W[j];
			E=D;
			D=C;
			C=rotateleft(B,30);
			B=A;
			A=temp;
		}
		for(int j=40;j<60;j++)
		{
			F= (B&C)|(B&D)|(C&D);
			temp = rotateleft(A,5)+F+E+K[2]+W[j];
			E=D;
			D=C;
			C=rotateleft(B,30);
			B=A;
			A=temp;
		}
		
		for(int j=60;j<80;j++)
		{
			F= B^C^D;
			temp = rotateleft(A,5)+F+E+K[3]+W[j];
			E=D;
			D=C;
			C=rotateleft(B,30);
			B=A;
			A=temp;
		}
	
		
		H[0]+=A;
		H[1]+=B;
		H[2]+=C;
		H[3]+=D;
		H[4]+=E;
		
		System.out.println(Integer.toHexString(H[0]));
		return null;
	}
	
	final static int rotateleft(int value, int bits)
	{
		int q=(value << bits) | (value>>>(32-bits));
		return q;
	}
	
	
	
	
}
