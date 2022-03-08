rm -rf ~/.orthodox
make re
mkdir -p ~/.orthodox
cp * ~/.orthodox
export PATH=$HOME/.orthodox:$PATH
echo "export PATH=$HOME/.orthodox:$PATH" >> $HOME/.zshrc
echo "export PATH=$HOME/.orthodox:$PATH" >> $HOME/.bashrc
make fclean
