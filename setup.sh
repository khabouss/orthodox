rm -rf ~/.orthodox
make re
mkdir -p ~/.orthodox
cp * ~/.orthodox
export PATH=$HOME/.orthodox:$PATH
echo "export PATH=$HOME/.orthodox:$PATH" >> $HOME/.zshrc
echo "export PATH=$HOME/.orthodox:$PATH" >> $HOME/.bashrc
make fclean
red=`tput setaf 1`
green=`tput setaf 2`
reset=`tput sgr0`
echo "${green}ALL DONE! ENJOY :D - github.com/khabouss/orthodox${reset}"
