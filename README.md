# 3DOpenSource
Open-Source software for 3D printing

Software requirements:
- In order to run some of the external libraries, you may need to install a c++ compiler. The c++ libraries were compiled and tested with Visual Studio 2019.

To get the software:
- Install "Git" (https://git-scm.com/downloads)
- open "Git Bash"
- move to the installation directory (e.g. "cd Documents")
- run "git clone https://github.com/andrea-luongo/3DOpenSource_development.git" (if you don't have access to the repo, provide your github username to aluo@mek.dtu.dk)
- CONGRATULATIONS!
- The BVH/ray intersection C++ source code can be found here: https://github.com/andrea-luongo/ray_tracer_pywrapper


To update the software:
- open "Git Bash"
- move to the installation directory (e.g. "cd Documents/3DOpenSource")
- run "git pull"
- YOU ARE AWESOME!

To Install on win-64:
- install Anaconda 64 bits
- open "3DOpenSource/resources"
- unzip "lrs_wq_sw_bundle_v02-10.zip"
- install "dln.3.0.2.exe"
- open "Anaconda Prompt" in the location of the software installation
- run "conda env create -f environment.yaml"
- THAT'S IMPRESSIVE!

To Update Anaconda environment:
- open "Anaconda Prompt" in the location of the software installation
- run "conda activate 3DOpenSource"
- run "conda env update --file environment.yaml"
- YOU ARE AN AMAZING HUMAN BEING!

To Run on win-64:

- open "Anaconda Prompt" in the location of the software installation
- run "conda activate 3DOpenSource"
- run "python __main__.py", or "python __main__.py --old" for old version of the software
- I KNEW YOU WERE WORTHY!

To install and run using venv:

- open a python terminal in the position of this project.
- create a new venv by running "py -m venv your_name"
- activate the environment ".\your_name\Scripts\activate"
- run "pip install -r requirements.txt"
