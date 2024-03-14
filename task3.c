#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	char* saltDES = "E1F53135E559C253";
	char* salt256 = "$5$E1F53135E559C253$";
	char* salt512 = "$6$E1F53135E559C253$";
	char* saltMD5 = "$1$E1F53135E559C253$";
	printf("hash: %s algorithm: DES salt: %s\n",crypt(argv[1],saltDES), saltDES);
	printf("hash: %s algorithm: MD5 salt: %s\n",crypt(argv[1],saltMD5), saltMD5);
	printf("hash: %s algorithm: SHA256 salt: %s\n",crypt(argv[1],salt256), salt256);
	printf("hash: %s algorithm: SHA512 salt: %s\n",crypt(argv[1],salt512), salt512);
	return 0;
}
