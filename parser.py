import argparse

parser = argparse.ArgumentParser()
parser.add_argument("file",help = "The file which needs to be ciphered/deciphered")
parser.add_argument("-c","--cipher",help = "flag to cipher the file",action="store_true")
parser.add_argument("-d","--decipher",help = "flag to decipher the file",action="store_true")

args = parser.parse_args()

print(args.file,args.cipher,args.decipher,end="\0")
