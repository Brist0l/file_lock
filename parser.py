import argparse

parser = argparse.ArgumentParser(
                    prog = "file_lock",
                    description = "ciphers/deciphers files")
parser.add_argument("file",help = "file which needs to be ciphered/deciphered")
parser.add_argument("-c","--cipher",help = "cipher the file",action="store_true")
parser.add_argument("-d","--decipher",help = "decipher the file",action="store_true")
parser.add_argument("-x","--delete",help = "delete the original file",action="store_true")
parser.add_argument("-s","--hide",help = "hide the file",action="store_true")

args = parser.parse_args()

print(args.file,args.cipher,args.decipher,args.delete,args.hide,end="\0")
