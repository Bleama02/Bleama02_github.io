# Compiling and Running Java Programs

## <u>**General Overview**</u>
These are the instructions for setting up, compiling, building, running, and debugging Java programs per platform. The settings included in this repo should work on any computer with Visual Studio Code. You will also need to have the proper compilers and debuggers installed (see below). These instructions assume the default directories for the compilers.


## <u>**Using VSC**</u>
Installation instructions for specific platforms are found in the subsequent sections. These next steps assume you have VSC and your compiler installed.

1. Open up the workspace using the file `_LaunchThis.code-workspace`. This should open up VSC as a workspace with all of the necessary settings. If the file type is not already associated with VSC, do so.
1. Create a new, blank file (`File->New File`) from VSC. 
1. Compile and run by hitting `[Ctrl]+[Shift]+B` on Windozzze or `[command]+[shift]+B` on Mac. You can also just use the menu `Terminal->Run Build Task...`. Select `Build and Run C/C++ Application`.
1. To debug, you can select `[F5]` or the menu `Debug->Start Debugging`.

> <b><u>File Names</u></b><br>
> All files MUST be named correctly as the assignment instructions dictate. This includes spacing (don't use any!), capitalization, name of the file, and the correct extensions (`.java`). Major points will be taken off for incorrect file names and/or missing files. 
>
> <b><u>Header Information</u></b><br>
> Please include all requested documents for this assignment in this repository. Each file MUST include a `COMMENT AREA` near the top of the page. The comment area must include the following three lines. All assignments for the remainder of this course must contain a variation of the following three lines. You will need to fill in the bracketed sections with the appropriate information (without the square brackets).
> ```
> Project Name: [Title of the Project]
> Author: [Your Full Name]
> Date Last Modified: [Date Modified]
> ```

---

## <u>**Installing (do these once)**</u>
### <u>General Installation (all platforms)</u>
#### Install Visual Studio Code ( https://code.visualstudio.com/ )
1. Go to the website above. Download and install the version appropriate to your computer.
1. The first time you launch VSC, it will probably try to install a few plugins for handling cpp files. This is good! If it needs a little push, you can start the plugin manager (`[command or Ctrl]+[Shift]+X`) and install `C/C++ for Visual Studio Code`.
1. Generally, you will start projects using the file `_LaunchThis.code-workspace`. This should open up VSC as a workspace with all of the necessary settings. If this file type is not already associated with VSC, do so.

---

#### Install Java JDK ( https://adoptopenjdk.net/?variant=openjdk11&jvmVariant=hotspot )

1. Go to the link above to find Java JDK. There are other versions of Java out there, but this will work the easiest.
1. Select `OpenJDK 11 (LTS)`.
1. Click the `Latest release` button.
1. Choose your platform (e.g. `Windows x64` or `macOS x64`).
1. Click `Install JDK` and download and install Java. Use the default settings.

---

### <u>Linux (Raspbian) Installation Specifics</u>

#### Install Visual Studio Code (Code-OSS)
1. If you've previously installed `code-oss` andit is not working properly (installs other than version 1.29), you'll need to purge it prior to starting:
    ```{bash}
    sudo apt-get purge code-oss
    ```
1. Download GPG signing key from PackageCloud: [https://packagecloud.io/headmelted/codebuilds/gpgkey](https://packagecloud.io/headmelted/codebuilds/gpgkey)
1. Import GPG key
    ```{bash}
    gpg --import /home/pi/Downloads/headmelted-code-oss-0CC3FD642696BFC8.pub.gpg
    gpg --list-keys
     ```
1. Install the PackageCloud repository for code-oss
    ```{bash}
    curl -s https://packagecloud.io/install/repositories/headmelted/codebuilds/script.deb.sh | sudo bash
    ```
1. Install code-oss
    ```{bash}
    sudo apt-get install code-oss=1.29.0-1539702238
    ```
1. Tell `apt` to hold at version 1.29, since 1.32 doesn't work properly
    ```{bash}
    sudo apt-mark hold code-oss
    ```
