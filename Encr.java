import java.math.BigInteger;
import java.util.Scanner;

public class Encr {
	static int[] H = {0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0};
    static int[] K = {0x5A827999, 0x6ED9EBA1, 0x8F1BBCDC, 0xCA62C1D6};

	public static void main(String[] args) {
		Scanner in =new Scanner(System.in);
		System.out.println("Enter text :");
		String password=in.nextLine();
		byte[] buffer=password.getBytes();
		String hash_val=SHA(buffer);
		
	}
	 private static byte[] padTheMessage(byte[] data) {
		 
		 int origLength=data.length;
         int padLength = 64 - origLength - 8; // (512/8 =64)
         byte[] thePad = new byte[padLength];
         thePad[0]=(byte) 0x80;				// settng it to 1
         /*for(int i=1;i<padLength;i++)
        	 thePad[i]=0;*/
         byte[] thelength = new byte[8];
         int lengthInBits = origLength * 8;
         String val = Integer.toBinaryString(lengthInBits);
         //System.out.println(val);
         byte[] bval = new BigInteger(val, 2).toByteArray();
         //System.out.println(bval.length);
         int temp=bval.length;
         for(int k=8-temp,j=0;k<8;k++,j++)
         {
        	 thelength[k]=bval[j];
         }
         temp=thelength.length;
         /*for(int i=0;i<temp;i++)
        	 System.out.print(thelength[i]+" ");
         System.out.println();*/
         byte[] output = new byte[origLength + padLength + 8];
         int i,p;
         temp=data.length;
         for(p=0, i=0;i<temp;i++,p++)
        	 output[i]=data[p];
         temp=thePad.length+data.length;
         for(p=0;i<temp;i++,p++)
        	 output[i]=thePad[p];
         temp=output.length;
         for(p=0;i<temp;i++,p++)
        	 output[i]=thelength[p];
         
         //System.out.println(output.length);
         temp=output.length;
         /*for(i=0;i<temp;i++)
 			System.out.print(output[i]+" ");*/
         return output;

     }
	 
	private static String SHA(byte[] buffer) {

		byte[] paddedMsg=padTheMessage(buffer);
		int[] W = new int[80];
        for (int outer = 0; outer < 16; outer++) {
            int temp = 0;
            for (int inner = 0; inner < 4; inner++) {
                temp = (paddedMsg[outer * 4 + inner] & 0x000000FF) << (24 - inner * 8);
                W[outer] = W[outer] | temp;
            }
        }

        for (int j = 16; j < 80; j++) {
            W[j] = rotateLeft(W[j - 3] ^ W[j - 8] ^ W[j - 14] ^ W[j - 16], 1);
        }
		int A,B,C,D,E,F,temp;
        A = H[0];
        B = H[1];
        C = H[2];
        D = H[3];
        E = H[4];

        for (int j = 0; j < 20; j++) {
            F = (B & C) | ((~B) & D);
            //	K = 0x5A827999;
            temp = rotateLeft(A, 5) + F + E + K[0] + W[j];
            //System.out.println(Integer.toHexString(K[0]));
            E = D;
            D = C;
            C = rotateLeft(B, 30);
            B = A;
            A = temp;
        }

        for (int j = 20; j < 40; j++) {
            F = B ^ C ^ D;
            //   K = 0x6ED9EBA1;
            temp = rotateLeft(A, 5) + F + E + K[1] + W[j];
            //System.out.println(Integer.toHexString(K[1]));
            E = D;
            D = C;
            C = rotateLeft(B, 30);
            B = A;
            A = temp;
        }

        for (int j = 40; j < 60; j++) {
            F = (B & C) | (B & D) | (C & D);
            //   K = 0x8F1BBCDC;
            temp = rotateLeft(A, 5) + F + E + K[2] + W[j];
            E = D;
            D = C;
            C = rotateLeft(B, 30);
            B = A;
            A = temp;
        }

        for (int j = 60; j < 80; j++) {
            F = B ^ C ^ D;
            //   K = 0xCA62C1D6;
            temp = rotateLeft(A, 5) + F + E + K[3] + W[j];
            E = D;
            D = C;
            C = rotateLeft(B, 30);
            B = A;
            A = temp;
        }

        H[0] += A;
        H[1] += B;
        H[2] += C;
        H[3] += D;
        H[4] += E;

        /*int n;
        for (n = 0; n < 16; n++) {
            System.out.println("W[" + n + "] = " + toHexString(W[n]));
        }*/

        System.out.println("Hash value = ");
        System.out.println("H0:" + Integer.toHexString(H[0]));
        System.out.println("H1:" + Integer.toHexString(H[1]));
        System.out.println("H2:" + Integer.toHexString(H[2]));
        System.out.println("H3:" + Integer.toHexString(H[3]));
        System.out.println("H4:" + Integer.toHexString(H[4]));
		return null;
	}
	final static int rotateLeft(int value, int bits) {
        int q = (value << bits) | (value >>> (32 - bits));
        return q;
    }
}