# LibFT
 🛠 Custom basic C library used for the '21 Codam curriculum

### Installation
This project assumes you have Make installed, otherwise you can copy paste the commands into your terminal.

```bash
# Clone:
$ git clone https://github.com/RubenNijhuis/LibFT.git

# Compile:
$ Make all
```

### Usage

Add this line to your .c file
```c
#include "libft.h`
```

And add the `libft.a` file that was created in the LibFT folder to your project.

Your finished folder structure should look like this.
```
/- Project
 |- main.c
 |- libft.a
 |- libft.h
 |- ...
```

### Notes
This project started during my academic year '21 at Codam. Due to a norm they have for the code certain functions
might be written in 'interesting' ways. In most cases these functions would be written in a differently structured
way improving speed or memory usage.

This library will scale with the functionality I require during my time at Codam. Therefore some functions that might
be obvious for you to use won't be added as I don't have a use for them.

Happy coding :)
