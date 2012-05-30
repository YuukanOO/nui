Source explanations
=================

Folders structure
-----------------
Since NUI aims to provide a platform independant GUI library through native OS API, all platform specific code must live in the native/ folder. Below is a simple explanation of the folders structure:

	- native/
		- gtk3/ : specific gtk members
		- win32/ : specific win32 members
		- nui_template/ : provide a template for new native implementation