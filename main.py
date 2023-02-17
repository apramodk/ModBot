import os, random, discord
from discord.ext import commands
# from python.authentication import send_email


client = commands.Bot(command_prefix='$')

# on bot connect to discord
@client.event
async def on_ready():
    print("connected to servers")


# fun/dumb bot commands
x = str('$hello\n $devin\n $feed\n $ping\n $auth [utk netid] [name]\n $gif\n')
gifs = ['asuna.gif', 'amungus.gif', 'rolly.gif', 'winky.gif']

@client.command()
async def helpme(ctx):
    await ctx.send(x)

# technical commands
@client.command()
async def ping(ctx):
    await ctx.send('Pong! {0}'.format(round(client.latency, 1)))

# # server utility commands
# @client.command()
# async def auth(ctx, arg1, arg2):
#     send_email(arg1)
#     await ctx.send('email sent to - ' + arg1 +'@vols.utk.edu *check spam folder*')

# # User Fun
# @client.command()
# async def play(ctx, arg1):


# misc commands
@client.command()
async def hello(ctx):
  await ctx.send('Hello!')

@client.command()
async def feed(ctx):  
  await ctx.send('yay!')
  await ctx.send(file=discord.File('python/gifs/treat.gif'))

@client.command()
async def gif(ctx):
    await ctx.send(file=discord.File('python/gifs/' + random.choice(gifs)))

@client.command()
async def devin(ctx):
    await ctx.send('Devin is foul')

# joining voice channel on play
@client.command(pass_context = True)
async def join(ctx):
  channel = ctx.message.author.voice.voice_channel
  await client.join_voice_channel(channel)

@client.command(pass_context = True)
async def leave(ctx):
  server = ctx.message.server
  voice_client = client.voice_client_in(server)
  


  
client.run(os.getenv('TOKEN'))
