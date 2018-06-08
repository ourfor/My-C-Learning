#!/bin/bash
#备份终端的一些设置，写一个一键安装脚本
#By author:ourfor. Date:20180608 Blog:https://ourfor.top

echo -e "该脚本将会安装以下程序:\n1.zsh\n2.zsh-theme-powerline\n3.vim-theme-airline\n4.neofetch\n5.brew\n5.curl&&wget"\n6.git\n7.zsh-autosuggestions、zsh-syntax-highlighting;
echo -e "·此脚本仅用于交流学习，请勿用于商业用途\n·博客：https://ourfor.top\n·QQ：2320813747"
cd ~

#安装brew
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"

#安装git
brew install git

#安装zsh、vim、curl、wget、make、nmap。
brew install zsh vim curl wget nmap 

#同步配置文件
sh -c "$(curl -fsSL https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh)" #github仓库安装同步zsh
cd ~
git clone https://github.com/jeremyFreeAgent/oh-my-zsh-powerline-theme.git
./oh-my-zsh-powerline-theme/install_in_omz.sh
git clone https://github.com/zsh-users/zsh-autosuggestions ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-autosuggestions #安装自动候选插件
git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-syntax-highlighting #安装命令高亮插件
git clone https://github.com/dylanaraps/neofetch.git&&cd neofetch
make&&make install #安装neofetch
#vim插件安装
cd ~
git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim


