"""

  This is a sample template for the log config file. Copy this file to 'logConfig.py' to have
  the system recognize your default logging type specifications.

"""


# This variable specifies which typed log messages that the client should listen to and report
ignore_types = []

# append a type to listen to
def ignore(type):
    ignore_types.append(type)

# These variables below describe per developer which types of log messages they want to ignore.
# For example, if I developer wishes to not see anything related to audio and ai, he would add
# ignore('ai') and ignore('audio'). Doing this achieves filtered logs.

# component section filters
ignore('game')

# you want to comment this out (allowing ai.tick messages) if you want to get 
# detailed logging about each ai agent's reinforcement (and then plot it using
# plot_server.py
# ignore('ai.tick')
ignore('python')

# unless ignored,
# this will print out a message saying exactly which element of an invalid 
# feature vector was out of bounds
ignore('ai.validate')
