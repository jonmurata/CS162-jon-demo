This is a demo to show off signals. This should help with Homework 1 and signal handling.

Files:

`demo`: the executable that you will run.

`demo.c`: the c file that you will edit.

`Makefile`: the Makefile that makes compiling demo.c easy.

#Demo:

Step 1: Familiarize yourself with the code.

Open demo.c and look at the different parts.
#define statements: This maps each of the signal values to their corresponding name.
do_nothing function: This is a function that does nothing!
main: the function that is called when the executable is run.

Step 2: Run the demo
Don't do anything with the code just yet.
Open a terminal window from this demo folder.
	Your path should look something like `~/<filepath>/SIGDEMO`
Run the demo with `./demo`
You should see the string "I love CS 162!" (one of the most popular strings to use in this class) printed out once per second. You also should not see any prompts to type in new commands.

Step 3: Q. How do I stop this?
	A. Signals!

Press `CTRL-C`
You should see that demo will stop printing out lines.

What happened: In your terminal window, there are predefined signals that you can send with keyboard shortcuts. This one happens to be the same as a copy shortcut (if you are a non-mac user), but it has even more meaning in a terminal setting. `CTRL-C` sends a `SIGINT` signal, which is a Terminate signal. As its name suggests, this tells the process to stop running.

Step 4: Ignore the `SIGINT` signal
Uncomment the line `signal (SIGINT, do_nothing);`
Run `make` in your terminal to recompile your changes.

What happened: You are telling your program that now you want the signal handler for `SIGINT` to be the `do_nothing` function. Since do_nothing does nothing, our ctrl-c trick shouldn't work any more when we run ./demo again. Try it out!

Step 5: Are we stuck?

There are other signals like CTRL-\. Let's use that to exit out of our program.

Notice that we have a different' exit message now. This is becuase ctrl-\ is a different type of signal. You can look into all the different types of signals on the signals discussion worksheet.

Step 6: Lets get really stuck.

Uncomment all of the lines in `demo.c`. This should ignore most of the main kill signals. There are others, but lets just pretend they don't exist right now.

Recompile and run the program now. Try to kill it. Oops, I guess we're really stuck now that we don't have our keyboard kill signals. Do we have to restart our computer? Leave it running forever? No! We can send a signal through another terminal window.

Q: But didn't we ignore all our signals? Doesn't that mean none of them will work now?

A: Not all signals are equal. We can redefine the signal handler for most signals, but not all of them. SIGKILL (with a value of 9) is one of them.

Step 7: Lock on your target.
	Find what you need to stop.

Open another terminal window and run `ps -A` which will list all running processes. Find our `demo` process and find its PID (Process ID).

Step 8: Go in for the kill.
	In that other terminal window, run `kill -9 <insert demo PID here>`

What happened: `SIGKILL` cannot be redirected to a differnet handler. Even though we tried to tell this signal to do nothing, we can't change how our OS handles it. This doesn't have a keyboard shortcut, so we had to send it through a new terminal with `kill`.
