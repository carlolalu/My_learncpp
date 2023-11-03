# my_learncpp
'learncpp.com' + random exercises

Here I add various exercises and eventually small projects to learn cpp, following mainly the website learncpp.com. Others are taken from the project euler (for which a high level language like python or julia would be better) or eventually edabit or similar.

PS: all these exercises are compiled with this command:
```
# compiler as learncpp.com adivises
# with the right standards in debug conf
 alias gpp-pedantic='g++ -ggdb -pedantic-errors -Wall -Weffc++ -Wextra -Werror -Wsign-conversion -std=c++20'
```

- update: the website `learncpp.com` is sometimes updated, and as can be verified in the middle of my tutorial it got updated. Thus the two folders. Because of this reason it becomes VERY important to havea  reference book, a pdf or similar, to which I can get acquainted to better retrieve information from it, rather than having this website, which is excellent to learn but surely not as a reference.

- update 09.11.2023: from now on I will try to use only `vim` to access the repo. The trick, in the end, is `:syntax on` and `filetype on`.

# Final Words

The chapter 'The End?' underlines that the journey has just started. Precisely points out that there are still topics to learn (I write here only the ones I know I would do on the medium time-range):
- design-patterns. For this I found the website https://refactoring.guru/design-patterns
- GUI applications. The website suggests a series of libraries: 'Popular choices include Qt, WxWidgets, SDL, and SFML. If you want to do 3d graphics, all of these frameworks support OpenGL'
- Internet&Networking. The website suggests to use the library Asio or Asio enhanced with Boost
- Multithreading

I hope to address most of this in the next repos I am gonna create. Precisely I hope to address design-patterns and GUI applications in another repo that I could call 'cpp-libraries', or to learn by doing in some project in 'trainspotter'. For the Internet I have already 'kurose-networking'. Regarding 'Multithreading' I hope to address the thing with rust, which should be much much easier than cpp regarding the topic.

