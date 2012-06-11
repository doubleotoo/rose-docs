Github Workflow
===============

## Syncing Your Machines

![Syncing Your Machines](http://www.dabbleboard.com/image?b=Guest1164946&i=3&c=bb5e8d169fabe2bbdc427461522b8c&t=.png")

1. Create a Github account at http://github.com.
2. Fork the [rose-compiler/rose](https://github.com/rose-compiler/rose) repository.
   (Forking the repository will create a copy of it in your account. This will be your working copy.)
3. `git-clone` your fork of the repository onto your working machine:

   ```bash
   $ git clone https://github.com/<username>/rose.git
   ```

   Cloning from Github will set your Git `origin` remote to be your Github repository. Then, pushing
   and pulling repository changes is trivial:

   ```bash
   $ git push origin <branch> # push changes to Github
   $ git pull origin <branch> # pull changes from Github
   ```

## Integrating Your Work

![Sending Pull Requests](http://www.dabbleboard.com/image?b=Guest1164946&i=5&c=6cc25bd6fe1e4280d7e986ba0a3e0b&t=.png)

You will want to regularly integrate your work with the ROSE Github repository.

To notify the ROSE team of your contributions, please send a Github **Pull Request** using the Github
web interface.

Once a ROSE team member has reviewed your work, it will be tested. If all of the tests pass, your work will
be integrated and the Github Pull Request will be closed.
