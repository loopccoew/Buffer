# Buffer
The buffer project series repository
# A Comparative Performance Analysis of Popular Algorithms in Languages you've studied

# Abstract

There are many programming languages existent in this world, each of them with its own pros and cons. C, CPP, Python are very extensively used for different purposes. While C and CPP have been used since a long time and are still in demand, Python has become popular in the recent times comparatively. This **research project focuses on the comparative analysis of these languages with other different aspects like processors, sorting techniques (Sorting refers to the arrangement of data in a particular order using a particular logic.) and amount of data given as input.**

# Research Methodology

The three languages that we chose for this project are  **C, C++ and Python.**

These are the most popular languages and used extensively in the industries which is why we chose them so that we could judge how their performance is with respect to each other.

The five sorting techniques that we chose for this project are **Bubble, Selection, Insertion, Merge and Radix Sort.**

All the research was done on *four different combinations of processors* mentioned in the sheet since factors like these change the readings by 5-10% which is quite small considering our readings, which in turn are already small.

The operating system that we chose for this research project is *Windows* since it is easily available and most widely used.

Talking about the compilers we were using for this project we tried to do it on Online compilers so that everybody would work on the same platform but the disadvantage of this technique is that network delay and speed of the internet used comes into the picture whose stabilization seemed difficult and would add up to the error in the result. So we ruled that technique out.

Same compiler of the same version for each language  across all machines were used to be on the same platform.

With respect to data, the slots of data chosen are **10,000 , 50,000 , 1,00,000 , 5,00,000 randomly generated numbers** which are common for the all the sorts across all the languages.

We first generated these positive random numbers once for each slot which are present in the .txt files and then used the same for our codes as in when required. By doing this we ensured the readings are taken for the same data to erase any kind of ambiguity. Since when you compare anything you need a common platform to draw conclusions.

The codes that we used for calculating the time execution for each slot of numbers and each language has been uploaded. Also the sheet wherein we compare the time readings for everything and the generate ratios among the languages and their respective graphs has been uploaded.


A single code was generated in each language for all the sorts with the aim to cut short any kind of errors generated.

All the language codes were run on all combinations of processors.

It was realized that in the later slots since the number of numbers increased manifold there was a slight variation in the readings being taken, so an average of five readings was taken for the last slot.

After taking the reading of execution timings for the above mentioned methodology, Comparison ratios were generated with all the permutations and graphs were plotted of the readings taken to make analysis simpler.
# Analysis

# Compiled VS Interpreted Languages Performance Analysis




## Compiled Languages

Compiled languages are converted directly into machine code that the processor can execute. As a result, they tend to be faster and more efficient to execute than interpreted languages. They also give the developer more control over hardware aspects, like memory management and CPU usage.

Compiled languages need a “build” step - they need to be manually compiled first. You need to “rebuild” the program every time you need to make a change.

Examples of pure compiled languages are C, C++, Erlang, Haskell, Rust, and Go.

##  Interpreted Languages

Interpreters will run through a program line by line and execute each command.

Interpreted languages were once known to be significantly slower than compiled languages. But, with the development of just-in-time compilation, that gap is shrinking.

Examples of common interpreted languages are Java, PHP, Ruby, Python, and JavaScript.

##  Advantages and Disadvantages

### Advantages of Compiled Languages

Programs compiled into native code at compile time usually tend to be faster than those translated at run time, due to the overhead of the translation process.

### Disadvantages of Compiled Languages
The most notable disadvantages are :-
-   Additional time needed to complete the entire compilation step before testing, and
-   Platform dependence of the generated binary code.

### Advantages of Interpreted Languages

An Interpreted language gives implementations some additional flexibility over compiled implementations. Because interpreters execute the source program code themselves, the code itself is platform independent (Java’s byte code, for example). Other features include dynamic typing, and smaller executable program size.
### Disadvantages of Interpreted Languages
 The most notable disadvantage is less execution speed compared to compiled languages


# Comparative Performance Analysis of Different Languages ( C , C++,Python)

## C vs C ++

The _C++ vs C Comparison Ratio_ columns, with **performance degradation ratios as high as 2.667**, clearly depict the unacceptable performance of C++ versus C. This is because

C++ allows you to write abstractions that compile-down to equivalent C. This means that with some care, a **C++ program will be at least as fast as a C one**. ***The advantage C++ gives over C is that it enables us to also build reusable abstractions with templates, OOP and functional composition.***

C++ gives you the tools to encode your intentions in the type-system. This allows the compiler to generate optimal binaries from your code.

## Python vs C ++

**The _Python vs C++_ columns show performance degradation ratios as high as 404(avg).**

When it comes to Python vs C++, it is a dynamic language which reduces complexity when it comes to collaborating and optimizes programmer efficiency.  **C++ has the advantage of being a statically typed language. The performance crown goes to C++ for creating a more compact and faster runtime code.**

## C vs Python

**Python is 662(avg) times slower than C because it is an interpreted language.**  python code will be interpreted, instead of directly by the CPU.

_This makes all the difference in the world, regarding performance._

Python code almost always runs in a virtual machine.

Another name for a virtual machine is a “bytecode interpreter”.

**_Interpreted code is always slower than direct machine code, because it takes a lot more instructions in order to implement an interpreted instruction than to implement an actual machine instruction._**


# Comparative Performance Analysis of Different Processors ( i3,i5,i7)


Intel’s current core processors are divided into three ranges(**Core i3, Core i5 and Core i7**), with several models in each range.

| **PERSONAL COMPUTER**| Clock Speed Range(Several Models) |
|--|--|
|**INTEL CORE I3**  | 3.4GHz – 4.2GHz |
|**INTEL CORE I5** | 2.4GHz – 3.8GHz |
|**INTEL CORE I7** | 2.9GHz – 4.2GHz
 |
The clock speed (or clock rate) is stated in megahertz (MHz) or gigahertz (GHz) and refers to the speed at which the processor can execute instructions. The faster the clock, the more instructions the processor can complete per second.

_All else being equal,_ processors with faster clock speeds process data faster than those with slower clock speeds.

This may be interesting, **the slowest Core i3 chips runs at a faster speed than the base Core i5 and Core i7.**

**Core i3 processors don’t have Turbo Boost** **, but Core i5 and Core i7s do.** Turbo Boost dynamically increases the clock speed of Core i5 and i7 processors when more power is required. This means that the chip can draw less power, produce less heat and only boost when it needs to. For example, although a Core i3-7300 runs at 4GHz compared to 3.5GHz for the Core i5-7600, the Core i5 chip can boost up to 4.1GHz when required, so will end up being quicker. A processor can only Turbo Boost for a limited amount of time. It is a significant part of the reason why Core i5 and Core i7 processors outperform Core i3 models in single-core-optimized tasks, even though they have lower base clock speeds.

**That’s why, i7 processor takes the least time to execute the program while i3 processor takes more time to execute than i5 as it does not have a Turbo Boost like i5 and i7.**


# Result

In this research based project we have described our work on **comparative analysis of popular algorithms in C, C++ and Python.**
The algorithms that we chose, were **Bubble sort, Selection sort, Insertion sort , Merge sort and Radix sort.**
The result obtained from above analysis says that, Bubble Sort, Selection Sort and Insertion Sort are fairly straightforward, but they are relatively inefficient except for small sized arrays. Merge Sort and Radix Sort are more complicated, but also much faster for large sized arrays. Merge Sort is, on average, the fastest algorithm. Bubble Sort  algorithm is the slowest.
In addition to this ,we have also established the fact that **performance wise C++ is the fastest language when compared with C and Python.**
Although there are minor differences between C and C++, **C++ is preferred over C** as it **enables the user to build reusable abstractions with templates, OOP and functional composition.**
**Python being an Interpreted language is slower than C and C++.**
Furthermore, we considered the processors of the machines used in this project as they are highly accountable for the performance time of the codes.
We have used intel core processors i3, i5 and i7. Because of absence of Turbo boost in processor **i3, it is the slowest, whereas i7 being the fastest processor.**
Since **performance improvement is the goal** thus this study gives a trend for **future research in order to minimize the time taken for sorting.**


# REFERENCES


[1] www.geeksforgeeks.com
[2] www.programiz.com
[3] www.researchgate.net
[4] www.semanticscholars.org
[5] www.cplusplus.com
[6] www.sciencedirect.com
[7] www.stackoverflow.com
[8] www.wikipedia.com
[9] www.kitchentablecomputers.com
[10] www.d.umn.edu
[11] www.whatis.techtarget.com
[12] www.tutorialsonpoint.com
[13] www.hackerearth.com
[14] www.softwaretestinghelp.com
[15] www.javapoint.com
[16] www.studytonight.com
[17] www.trustedreviews.com
[18] www.cs.stackexchange.com
[19] www.academia.edu
[20] www.educative.io
[21] www.ijlcenca.in
[22] www.sce.carleton.ca

|# A Comparative Performance Analysis of Popular Algorithms in Languages you've studied

# Abstract

There are many programming languages existent in this world, each of them with its own pros and cons. C, CPP, Python are very extensively used for different purposes. While C and CPP have been used since a long time and are still in demand, Python has become popular in the recent times comparatively. This **research project focuses on the comparative analysis of these languages with other different aspects like processors, sorting techniques (Sorting refers to the arrangement of data in a particular order using a particular logic.) and amount of data given as input.**

# Research Methodology

The three languages that we chose for this project are  **C, C++ and Python.**

These are the most popular languages and used extensively in the industries which is why we chose them so that we could judge how their performance is with respect to each other.

The five sorting techniques that we chose for this project are **Bubble, Selection, Insertion, Merge and Radix Sort.**

All the research was done on *four different combinations of processors* mentioned in the sheet since factors like these change the readings by 5-10% which is quite small considering our readings, which in turn are already small.

The operating system that we chose for this research project is *Windows* since it is easily available and most widely used.

Talking about the compilers we were using for this project we tried to do it on Online compilers so that everybody would work on the same platform but the disadvantage of this technique is that network delay and speed of the internet used comes into the picture whose stabilization seemed difficult and would add up to the error in the result. So we ruled that technique out.

Same compiler of the same version for each language  across all machines were used to be on the same platform.

With respect to data, the slots of data chosen are **10,000 , 50,000 , 1,00,000 , 5,00,000 randomly generated numbers** which are common for the all the sorts across all the languages.

We first generated these positive random numbers once for each slot which are present in the .txt files and then used the same for our codes as in when required. By doing this we ensured the readings are taken for the same data to erase any kind of ambiguity. Since when you compare anything you need a common platform to draw conclusions.

The codes that we used for calculating the time execution for each slot of numbers and each language has been uploaded. Also the sheet wherein we compare the time readings for everything and the generate ratios among the languages and their respective graphs has been uploaded.


A single code was generated in each language for all the sorts with the aim to cut short any kind of errors generated.

All the language codes were run on all combinations of processors.

It was realized that in the later slots since the number of numbers increased manifold there was a slight variation in the readings being taken, so an average of five readings was taken for the last slot.

After taking the reading of execution timings for the above mentioned methodology, Comparison ratios were generated with all the permutations and graphs were plotted of the readings taken to make analysis simpler.
# Analysis

# Compiled VS Interpreted Languages Performance Analysis




## Compiled Languages

Compiled languages are converted directly into machine code that the processor can execute. As a result, they tend to be faster and more efficient to execute than interpreted languages. They also give the developer more control over hardware aspects, like memory management and CPU usage.

Compiled languages need a “build” step - they need to be manually compiled first. You need to “rebuild” the program every time you need to make a change.

Examples of pure compiled languages are C, C++, Erlang, Haskell, Rust, and Go.

##  Interpreted Languages

Interpreters will run through a program line by line and execute each command.

Interpreted languages were once known to be significantly slower than compiled languages. But, with the development of just-in-time compilation, that gap is shrinking.

Examples of common interpreted languages are Java, PHP, Ruby, Python, and JavaScript.

##  Advantages and Disadvantages

### Advantages of Compiled Languages

Programs compiled into native code at compile time usually tend to be faster than those translated at run time, due to the overhead of the translation process.

### Disadvantages of Compiled Languages
The most notable disadvantages are :-
-   Additional time needed to complete the entire compilation step before testing, and
-   Platform dependence of the generated binary code.

### Advantages of Interpreted Languages

An Interpreted language gives implementations some additional flexibility over compiled implementations. Because interpreters execute the source program code themselves, the code itself is platform independent (Java’s byte code, for example). Other features include dynamic typing, and smaller executable program size.
### Disadvantages of Interpreted Languages
 The most notable disadvantage is less execution speed compared to compiled languages


# Comparative Performance Analysis of Different Languages ( C , C++,Python)

## C vs C ++

The _C++ vs C Comparison Ratio_ columns, with **performance degradation ratios as high as 2.667**, clearly depict the unacceptable performance of C++ versus C. This is because

C++ allows you to write abstractions that compile-down to equivalent C. This means that with some care, a **C++ program will be at least as fast as a C one**. ***The advantage C++ gives over C is that it enables us to also build reusable abstractions with templates, OOP and functional composition.***

C++ gives you the tools to encode your intentions in the type-system. This allows the compiler to generate optimal binaries from your code.

## Python vs C ++

**The _Python vs C++_ columns show performance degradation ratios as high as 404(avg).**

When it comes to Python vs C++, it is a dynamic language which reduces complexity when it comes to collaborating and optimizes programmer efficiency.  **C++ has the advantage of being a statically typed language. The performance crown goes to C++ for creating a more compact and faster runtime code.**

## C vs Python

**Python is 662(avg) times slower than C because it is an interpreted language.**  python code will be interpreted, instead of directly by the CPU.

_This makes all the difference in the world, regarding performance._

Python code almost always runs in a virtual machine.

Another name for a virtual machine is a “bytecode interpreter”.

**_Interpreted code is always slower than direct machine code, because it takes a lot more instructions in order to implement an interpreted instruction than to implement an actual machine instruction._**


# Comparative Performance Analysis of Different Processors ( i3,i5,i7)


Intel’s current core processors are divided into three ranges(**Core i3, Core i5 and Core i7**), with several models in each range.

| **PERSONAL COMPUTER**| Clock Speed Range(Several Models) |
|--|--|
|**INTEL CORE I3**  | 3.4GHz – 4.2GHz |
|**INTEL CORE I5** | 2.4GHz – 3.8GHz |
|**INTEL CORE I7** | 2.9GHz – 4.2GHz
 |
The clock speed (or clock rate) is stated in megahertz (MHz) or gigahertz (GHz) and refers to the speed at which the processor can execute instructions. The faster the clock, the more instructions the processor can complete per second.

_All else being equal,_ processors with faster clock speeds process data faster than those with slower clock speeds.

This may be interesting, **the slowest Core i3 chips runs at a faster speed than the base Core i5 and Core i7.**

**Core i3 processors don’t have Turbo Boost** **, but Core i5 and Core i7s do.** Turbo Boost dynamically increases the clock speed of Core i5 and i7 processors when more power is required. This means that the chip can draw less power, produce less heat and only boost when it needs to. For example, although a Core i3-7300 runs at 4GHz compared to 3.5GHz for the Core i5-7600, the Core i5 chip can boost up to 4.1GHz when required, so will end up being quicker. A processor can only Turbo Boost for a limited amount of time. It is a significant part of the reason why Core i5 and Core i7 processors outperform Core i3 models in single-core-optimized tasks, even though they have lower base clock speeds.

**That’s why, i7 processor takes the least time to execute the program while i3 processor takes more time to execute than i5 as it does not have a Turbo Boost like i5 and i7.**


# Result

In this research based project we have described our work on **comparative analysis of popular algorithms in C, C++ and Python.**
The algorithms that we chose, were **Bubble sort, Selection sort, Insertion sort , Merge sort and Radix sort.**
The result obtained from above analysis says that, Bubble Sort, Selection Sort and Insertion Sort are fairly straightforward, but they are relatively inefficient except for small sized arrays. Merge Sort and Radix Sort are more complicated, but also much faster for large sized arrays. Merge Sort is, on average, the fastest algorithm. Bubble Sort  algorithm is the slowest.
In addition to this ,we have also established the fact that **performance wise C++ is the fastest language when compared with C and Python.**
Although there are minor differences between C and C++, **C++ is preferred over C** as it **enables the user to build reusable abstractions with templates, OOP and functional composition.**
**Python being an Interpreted language is slower than C and C++.**
Furthermore, we considered the processors of the machines used in this project as they are highly accountable for the performance time of the codes.
We have used intel core processors i3, i5 and i7. Because of absence of Turbo boost in processor **i3, it is the slowest, whereas i7 being the fastest processor.**
Since **performance improvement is the goal** thus this study gives a trend for **future research in order to minimize the time taken for sorting.**


# REFERENCES


[1] www.geeksforgeeks.com
[2] www.programiz.com
[3] www.researchgate.net
[4] www.semanticscholars.org
[5] www.cplusplus.com
[6] www.sciencedirect.com
[7] www.stackoverflow.com
[8] www.wikipedia.com
[9] www.kitchentablecomputers.com
[10] www.d.umn.edu
[11] www.whatis.techtarget.com
[12] www.tutorialsonpoint.com
[13] www.hackerearth.com
[14] www.softwaretestinghelp.com
[15] www.javapoint.com
[16] www.studytonight.com
[17] www.trustedreviews.com
[18] www.cs.stackexchange.com
[19] www.academia.edu
[20] www.educative.io
[21] www.ijlcenca.in
[22] www.sce.carleton.ca




# A Comparative Performance Analysis of Popular Algorithms in Languages you've studied

# Abstract

There are many programming languages existent in this world, each of them with its own pros and cons. C, CPP, Python are very extensively used for different purposes. While C and CPP have been used since a long time and are still in demand, Python has become popular in the recent times comparatively. This **research project focuses on the comparative analysis of these languages with other different aspects like processors, sorting techniques (Sorting refers to the arrangement of data in a particular order using a particular logic.) and amount of data given as input.**

# Research Methodology

The three languages that we chose for this project are  **C, C++ and Python.**

These are the most popular languages and used extensively in the industries which is why we chose them so that we could judge how their performance is with respect to each other.

The five sorting techniques that we chose for this project are **Bubble, Selection, Insertion, Merge and Radix Sort.**

All the research was done on *four different combinations of processors* mentioned in the sheet since factors like these change the readings by 5-10% which is quite small considering our readings, which in turn are already small.

The operating system that we chose for this research project is *Windows* since it is easily available and most widely used.

Talking about the compilers we were using for this project we tried to do it on Online compilers so that everybody would work on the same platform but the disadvantage of this technique is that network delay and speed of the internet used comes into the picture whose stabilization seemed difficult and would add up to the error in the result. So we ruled that technique out.

Same compiler of the same version for each language  across all machines were used to be on the same platform.

With respect to data, the slots of data chosen are **10,000 , 50,000 , 1,00,000 , 5,00,000 randomly generated numbers** which are common for the all the sorts across all the languages.

We first generated these positive random numbers once for each slot which are present in the .txt files and then used the same for our codes as in when required. By doing this we ensured the readings are taken for the same data to erase any kind of ambiguity. Since when you compare anything you need a common platform to draw conclusions.

The codes that we used for calculating the time execution for each slot of numbers and each language has been uploaded. Also the sheet wherein we compare the time readings for everything and the generate ratios among the languages and their respective graphs has been uploaded.


A single code was generated in each language for all the sorts with the aim to cut short any kind of errors generated.

All the language codes were run on all combinations of processors.

It was realized that in the later slots since the number of numbers increased manifold there was a slight variation in the readings being taken, so an average of five readings was taken for the last slot.

After taking the reading of execution timings for the above mentioned methodology, Comparison ratios were generated with all the permutations and graphs were plotted of the readings taken to make analysis simpler.
# Analysis

# Compiled VS Interpreted Languages Performance Analysis




## Compiled Languages

Compiled languages are converted directly into machine code that the processor can execute. As a result, they tend to be faster and more efficient to execute than interpreted languages. They also give the developer more control over hardware aspects, like memory management and CPU usage.

Compiled languages need a “build” step - they need to be manually compiled first. You need to “rebuild” the program every time you need to make a change.

Examples of pure compiled languages are C, C++, Erlang, Haskell, Rust, and Go.

##  Interpreted Languages

Interpreters will run through a program line by line and execute each command.

Interpreted languages were once known to be significantly slower than compiled languages. But, with the development of just-in-time compilation, that gap is shrinking.

Examples of common interpreted languages are Java, PHP, Ruby, Python, and JavaScript.

##  Advantages and Disadvantages

### Advantages of Compiled Languages

Programs compiled into native code at compile time usually tend to be faster than those translated at run time, due to the overhead of the translation process.

### Disadvantages of Compiled Languages
The most notable disadvantages are :-
-   Additional time needed to complete the entire compilation step before testing, and
-   Platform dependence of the generated binary code.

### Advantages of Interpreted Languages

An Interpreted language gives implementations some additional flexibility over compiled implementations. Because interpreters execute the source program code themselves, the code itself is platform independent (Java’s byte code, for example). Other features include dynamic typing, and smaller executable program size.
### Disadvantages of Interpreted Languages
 The most notable disadvantage is less execution speed compared to compiled languages


# Comparative Performance Analysis of Different Languages ( C , C++,Python)

## C vs C ++

The _C++ vs C Comparison Ratio_ columns, with **performance degradation ratios as high as 2.667**, clearly depict the unacceptable performance of C++ versus C. This is because

C++ allows you to write abstractions that compile-down to equivalent C. This means that with some care, a **C++ program will be at least as fast as a C one**. ***The advantage C++ gives over C is that it enables us to also build reusable abstractions with templates, OOP and functional composition.***

C++ gives you the tools to encode your intentions in the type-system. This allows the compiler to generate optimal binaries from your code.

## Python vs C ++

**The _Python vs C++_ columns show performance degradation ratios as high as 404(avg).**

When it comes to Python vs C++, it is a dynamic language which reduces complexity when it comes to collaborating and optimizes programmer efficiency.  **C++ has the advantage of being a statically typed language. The performance crown goes to C++ for creating a more compact and faster runtime code.**

## C vs Python

**Python is 662(avg) times slower than C because it is an interpreted language.**  python code will be interpreted, instead of directly by the CPU.

_This makes all the difference in the world, regarding performance._

Python code almost always runs in a virtual machine.

Another name for a virtual machine is a “bytecode interpreter”.

**_Interpreted code is always slower than direct machine code, because it takes a lot more instructions in order to implement an interpreted instruction than to implement an actual machine instruction._**


# Comparative Performance Analysis of Different Processors ( i3,i5,i7)


Intel’s current core processors are divided into three ranges(**Core i3, Core i5 and Core i7**), with several models in each range.

| **PERSONAL COMPUTER**| Clock Speed Range(Several Models) |
|--|--|
|**INTEL CORE I3**  | 3.4GHz – 4.2GHz |
|**INTEL CORE I5** | 2.4GHz – 3.8GHz |
|**INTEL CORE I7** | 2.9GHz – 4.2GHz
 |
The clock speed (or clock rate) is stated in megahertz (MHz) or gigahertz (GHz) and refers to the speed at which the processor can execute instructions. The faster the clock, the more instructions the processor can complete per second.

_All else being equal,_ processors with faster clock speeds process data faster than those with slower clock speeds.

This may be interesting, **the slowest Core i3 chips runs at a faster speed than the base Core i5 and Core i7.**

**Core i3 processors don’t have Turbo Boost** **, but Core i5 and Core i7s do.** Turbo Boost dynamically increases the clock speed of Core i5 and i7 processors when more power is required. This means that the chip can draw less power, produce less heat and only boost when it needs to. For example, although a Core i3-7300 runs at 4GHz compared to 3.5GHz for the Core i5-7600, the Core i5 chip can boost up to 4.1GHz when required, so will end up being quicker. A processor can only Turbo Boost for a limited amount of time. It is a significant part of the reason why Core i5 and Core i7 processors outperform Core i3 models in single-core-optimized tasks, even though they have lower base clock speeds.

**That’s why, i7 processor takes the least time to execute the program while i3 processor takes more time to execute than i5 as it does not have a Turbo Boost like i5 and i7.**


# Result

In this research based project we have described our work on **comparative analysis of popular algorithms in C, C++ and Python.**
The algorithms that we chose, were **Bubble sort, Selection sort, Insertion sort , Merge sort and Radix sort.**
The result obtained from above analysis says that, Bubble Sort, Selection Sort and Insertion Sort are fairly straightforward, but they are relatively inefficient except for small sized arrays. Merge Sort and Radix Sort are more complicated, but also much faster for large sized arrays. Merge Sort is, on average, the fastest algorithm. Bubble Sort  algorithm is the slowest.
In addition to this ,we have also established the fact that **performance wise C++ is the fastest language when compared with C and Python.**
Although there are minor differences between C and C++, **C++ is preferred over C** as it **enables the user to build reusable abstractions with templates, OOP and functional composition.**
**Python being an Interpreted language is slower than C and C++.**
Furthermore, we considered the processors of the machines used in this project as they are highly accountable for the performance time of the codes.
We have used intel core processors i3, i5 and i7. Because of absence of Turbo boost in processor **i3, it is the slowest, whereas i7 being the fastest processor.**
Since **performance improvement is the goal** thus this study gives a trend for **future research in order to minimize the time taken for sorting.**


# REFERENCES


[1] www.geeksforgeeks.com
[2] www.programiz.com
[3] www.researchgate.net
[4] www.semanticscholars.org
[5] www.cplusplus.com
[6] www.sciencedirect.com
[7] www.stackoverflow.com
[8] www.wikipedia.com
[9] www.kitchentablecomputers.com
[10] www.d.umn.edu
[11] www.whatis.techtarget.com
[12] www.tutorialsonpoint.com
[13] www.hackerearth.com
[14] www.softwaretestinghelp.com
[15] www.javapoint.com
[16] www.studytonight.com
[17] www.trustedreviews.com
[18] www.cs.stackexchange.com
[19] www.academia.edu
[20] www.educative.io
[21] www.ijlcenca.in
[22] www.sce.carleton.ca





```
