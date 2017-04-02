using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Graphics;

using System;
using System.Collections.Generic;
using HashTableProject;
//using System.Diagnostics;

namespace Game1
{





    /// <summary>
    /// This is the main type for your game.
    /// </summary>
    public class Game1 : Game
    {

        // Content directories

        /// <summary>
        /// Texture directory
        /// </summary>
        string texDir = "Content/textures/";

        // Utility variables
        Vector2 baseVec = new Vector2(1, 1);


        // Player vars
        float moveSpeed = 0.1f;

        GraphicsDeviceManager graphics;
        SpriteBatch spriteBatch;

        private Texture2D m_playerSpr;

        public static Player player {get{ return m_player; } }

        // Screen
        static float m_screenHeight;
        static float m_screenWidth;
        public static float screenHeight { get { return m_screenHeight; } }
        public static float screenWidth { get { return m_screenWidth; } }


        // Objects

        string playerStr = "player";
        string enemyStr = "enemy1";

        private static Player m_player = new Player("player","player",10);
        private Enemy m_testEnemy = new Enemy("enemy1","enemy",10);
        private HideLoc m_bush1 = new HideLoc("bush1", "hideloc", 0);
        Scene m_scene1 = new Scene();

        GameGrid m_grid;
        Texture2D testSprite;

        // Textures
        Table<string, Texture2D> m_textures;

        int m_texLength = 0;


        public Game1()
        {
            graphics = new GraphicsDeviceManager(this);
            Content.RootDirectory = "Content";
        }
        
        string[] m_texArray;

        /// <summary>
        /// Allows the game to perform any initialization it needs to before starting to run.
        /// This is where it can query for any required services and load any non-graphic
        /// related content.  Calling base.Initialize will enumerate through any components
        /// and initialize them as well.
        /// </summary>
        protected override void Initialize()
        {


            //m_grid.
            Console.WriteLine("Initialising...");
            // TODO: Add your initialization logic here

            base.Initialize();

            m_screenHeight = GraphicsDevice.Viewport.Bounds.Height;
            m_screenWidth = GraphicsDevice.Viewport.Bounds.Width;

            m_grid = new GameGrid(10, 10, 0.1f);
            // Load textures.
            m_texArray = new string[]
                {
                    "player",
                    "abc"

                };
            m_textures = LoadTextures(m_texArray, texDir);

            // Initialise objects.
            World.player = m_player;

            Texture2D playerSprite;
            if (!m_textures.ContainsKey(texDir + "player"))
            {
                Console.WriteLine("No player tex in map");
                
            }
            
            if (!m_textures.ContainsKey(texDir + "abc"))
            {
                Console.WriteLine("No test tex in map");
                
            }

            playerSprite = m_textures.Get(texDir + "player");

            testSprite = m_textures.Get(texDir + "abc");




            testSprite = m_textures.Get(texDir + "abc");


            // Scene 1 init
            m_player.sprite = playerSprite;
            m_player.pos2D = m_grid.GetPoint(0.5f, 0.5f); //m_screenWidth / 2f, m_screenHeight / 2f);
            m_scene1.AddObject(m_player);

            m_testEnemy.sprite = playerSprite;
            m_testEnemy.pos2D = new Vector2(200, 200);
            List<Vector2> patrolPath = new List<Vector2>();
            patrolPath.Add(m_grid.GetPoint(0.1f, 0.1f));
            patrolPath.Add(m_grid.GetPoint(0.1f, 0.5f));
            patrolPath.Add(m_grid.GetPoint(0.2f, 0.3f));
            m_testEnemy.patrolPath = patrolPath;
            m_testEnemy.StartPatrol(0);
            m_scene1.AddObject(m_testEnemy);

            m_bush1.sprite = playerSprite;
            m_scene1.AddObject(m_bush1);


            //m_testEnemy.AddCollisionTrigger(m_player, OtherTakesDamage);

            // m_player.AddCollisionTrigger(m_testEnemy, OtherTakesDamage);

            m_testEnemy.AddCollisionTrigger(m_player, EnemyHitsPlayer);



            Console.WriteLine("Initialisation complete.");

        }
        
        void OtherTakesDamage(GameTime gameTime, GameObject2D thisobj, GameObject2D other)
        {
            
            //Console.WriteLine("Collision event triggered: Player hit enemy.");
            other.sprite = testSprite;
            other.RegisterHit(gameTime, 10);
        }

        void EnemyHitsPlayer(GameTime gameTime, Enemy thisobj, GameObject2D other)
        {

            //Console.WriteLine("Collision event triggered: Player hit enemy.");
            other.sprite = testSprite;
            other.RegisterHit(gameTime, 10);
            thisobj.SetEnemyState(Enemy.EnemyState.patrolling);
            
        }



        Table<string,Texture2D> LoadTextures(string[] tex, string dir)
        {
            Table<string, Texture2D> textures = new Table<string, Texture2D>(tex.Length * 10);

            for (int i = 0; i < m_texArray.Length; i++)
            {
                //Console.WriteLine(i);
                string texstr = dir + tex[i];
                try
                {
                    Texture2D t = Content.Load<Texture2D>(texstr);
                    textures.Add(texstr,t );

                }
                catch (Exception e)
                {
                    Console.WriteLine("ERROR. Exception while trying to read texture " + texstr + ": ");
                    ShowException(e);

                    //catch()
                }
               
            }
            return textures;
        }

        void ShowException(Exception e)
        {
            Console.Write(e.Message+"\n");
            Console.WriteLine("Input e to view full exception or enter to continue.");
            string str = Console.ReadLine();
            if (str.ToUpper() == "E")
            {
                Console.WriteLine(e);
            }
            if(str != "")
            {
                Console.ReadLine();

            }

        }

        /// <summary>
        /// LoadContent will be called once per game and is the place to load
        /// all of your content.
        /// </summary>
        protected override void LoadContent()
        {
            // Create a new SpriteBatch, which can be used to draw textures.
            spriteBatch = new SpriteBatch(GraphicsDevice);

            // TODO: use this.Content to load your game content here
        }

        /// <summary>
        /// UnloadContent will be called once per game and is the place to unload
        /// game-specific content.
        /// </summary>
        protected override void UnloadContent()
        {
            // TODO: Unload any non ContentManager content here
        }

        /// <summary>
        /// Allows the game to run logic such as updating the world,
        /// checking for collisions, gathering input, and playing audio.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Update(GameTime gameTime)
        {
            Input.Update();
            if(Input.keyState.IsKeyDown(Keys.Escape))
            {
                Exit();
            }
            //m_player.Update(gameTime);

            m_scene1.Update(gameTime);




            //if (GamePad.GetState(PlayerIndex.One).Buttons.Back == ButtonState.Pressed || Keyboard.GetState().IsKeyDown(Keys.Escape))
               // Exit();

            base.Update(gameTime);

        }

        /// <summary>
        /// This is called when the game should draw itself.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Draw(GameTime gameTime)
        {
            GraphicsDevice.Clear(Color.CornflowerBlue);
            spriteBatch.Begin();

            base.Draw(gameTime);

            //m_player.Render(spriteBatch);
            m_scene1.Render(spriteBatch);


            spriteBatch.End();
        }
        


    }
}
