# CyberVandals Readme

Readme file for the team

## Getting Started

Clone or download the repository from [GitHub](https://github.com/). Your can also do the following:
```
• open a terminal, command line utility, or shell
• type: git clone followed by the url of the game 
  and followed by the name you want to give to your
  local copy of the game. 
  example: git clone https://github.com/CyberVandals/fishnchips fishNchips
This command will download a copy of the repository into your computer.
```
### Basic workflow

```
Let's say you have made some changes to your local copy of the repository. And you want to push those changes to the master branch of the repository. The following commands will let you do that:
in the command line tool (or shell) enter:
git pull origin master
              -> always make sure to pull the remote changes
git add .     -> to keep track of your local changes (notice there is a period after 'add')
git status    -> to see the files you are tracking
git commit -am "some message about the changes"   
              -> to save the changes locally
git log       -> to see the local changes made so far
git push origin master    
              -> this will push the changes to the remote master branch (the repository master branch)
```

### Reverting commits

When you want to revert to a previous commit. Let's say you made a local commit and want to go back to previous states. You can type following commands

```
git log       -> first list all the changes (commits)
                 made so far. And copy or type the id of the commit you want to go back to
git checkout id   -> where id is the commit id (an alphanumeric value)
```

### Disaster recovery
It is important to avoid the use of the git command modifier 'force' when pushing to the remote master branch. Create pull requests for additional features to be added.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
