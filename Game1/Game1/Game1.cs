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
        private static Player m_player = new Player("player","player",10);
        
        Scene m_scene1 = new Scene();

        GameGrid m_grid;
        Texture2D testSprite;

        // Textures
        Table<string, Texture2D> m_textures;
        
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
            
            Console.WriteLine("Initialising...");

            base.Initialize();

            Render2D.Instance.Init(GraphicsDevice);

            m_screenHeight = GraphicsDevice.Viewport.Bounds.Height;
            m_screenWidth = GraphicsDevice.Viewport.Bounds.Width;

            m_grid = new GameGrid(10, 10, 0.1f);
            // Load textures.
            // Load textures.
            m_texArray = new string[]
                {
                    "player",
                    "abc",
                    "quendaspritesheet1",
                    "quendaspritesheet2"
                };
            m_textures = LoadTextures(m_texArray, texDir);

            // Initialise objects.
            World.player = m_player;

            if (!m_textures.ContainsKey(texDir + "player"))
            {
                Console.WriteLine("No player tex in map");

            }



            testSprite = m_textures.Get(texDir + "abc");



            // Scene 1 init
            Texture2D quendaSpritesLR = m_textures.Get(texDir + "quendaspritesheet1");
            Texture2D quendaSpritesUD = m_textures.Get(texDir + "quendaspritesheet2");
            AnimatedSprite playerRunUp = new AnimatedSprite(quendaSpritesUD, 1, 4);
            AnimatedSprite playerRunLeft = new AnimatedSprite(quendaSpritesLR, 5, 2, 0, 5);
            playerRunLeft.FlipHorizontal(true);
            AnimatedSprite playerRunDown = new AnimatedSprite(quendaSpritesUD, 1, 4);
            playerRunDown.FlipVertical(true);
            AnimatedSprite playerRunRight = new AnimatedSprite(quendaSpritesLR, 5, 2, 0, 5);

            m_player.scale = new Vector2(0.1f, 0.1f);
            AnimatedSprite playerIdle = new AnimatedSprite(m_textures.Get(texDir + "quendaspritesheet1"), 5, 2, 0, 1);

            m_player.AddAnimSprite("runUp", playerRunUp);
            m_player.AddAnimSprite("runLeft", playerRunLeft);
            m_player.AddAnimSprite("runDown", playerRunDown);
            m_player.AddAnimSprite("runRight", playerRunRight);
            m_player.AddAnimSprite("idle", playerIdle);
            m_player.SetAnim("idle");
            m_player.defaultAnim = "idle";
            m_player.pos2D = m_grid.GetPoint(0.5f, 0.5f);

            m_scene1.AddObject(m_player);

            Enemy m_testEnemy = new Enemy("enemy1", "enemy", 10);
            

            AnimatedSprite enemyIdle = new AnimatedSprite(quendaSpritesUD, 1, 4);


            m_testEnemy.scale = new Vector2(0.1f, 0.1f);
            m_testEnemy.AddAnimSprite("idle", enemyIdle);
            m_testEnemy.SetAnim("idle");
            m_testEnemy.defaultAnim = "idle";
            m_testEnemy.pos2D = m_grid.GetPoint(0.2f, 0.2f);
            

            List<Vector2> patrolPath = new List<Vector2>();
            patrolPath.Add(m_grid.GetPoint(0.1f, 0.1f));
            patrolPath.Add(m_grid.GetPoint(0.1f, 0.5f));
            patrolPath.Add(m_grid.GetPoint(0.2f, 0.3f));
            patrolPath.Add(m_grid.GetPoint(0.5f, 0.7f));
            patrolPath.Add(m_grid.GetPoint(0.6f, 0.7f));
            patrolPath.Add(m_grid.GetPoint(0.9f, 0.8f));
            m_testEnemy.patrolPath = patrolPath;
            m_testEnemy.StartPatrol(0);
            m_testEnemy.SetEnemyState(Enemy.EnemyState.patrolling);

            m_scene1.AddObject(m_testEnemy);


            //GameObject2D m_collisionTest = new GameObject2D("col", "col", 0);

            HideLoc m_bush1 = new HideLoc("bush1", "hideloc", 0);
            HideLoc m_bush2 = new HideLoc("bush2", "hideloc", 0);
            HideLoc m_bush3 = new HideLoc("bush3", "hideloc", 0);
            HideLoc m_bush4 = new HideLoc("bush4", "hideloc", 0);
            HideLoc m_bush5 = new HideLoc("bush5", "hideloc", 0);

            m_bush1.AddAnimSprite("idle", playerRunLeft);
            m_bush1.scale = new Vector2(0.1f, 0.1f);
            m_bush1.SetAnim("idle");

            m_bush1.pos2D = m_grid.GetPoint(0.9f, 0.2f);

            m_bush2 = new HideLoc("bush2", m_bush1);
            m_bush2.pos2D = m_grid.GetPoint(0.9f, 0.9f);

            m_bush3 = new HideLoc("bush3", m_bush1);
            m_bush3.pos2D = m_grid.GetPoint(0.4f, 0.7f);

            m_bush4 = new HideLoc("bush4", m_bush1);
            m_bush4.pos2D = m_grid.GetPoint(0.7f, 0.2f);
       
            m_bush5 = new HideLoc("bush5", m_bush1);
            m_bush5.pos2D = m_grid.GetPoint(0.3f, 0.56f);

            m_scene1.AddObject(m_bush1);
            m_scene1.AddObject(m_bush2);
            m_scene1.AddObject(m_bush3);
            m_scene1.AddObject(m_bush4);
            m_scene1.AddObject(m_bush5);

            m_testEnemy.AddCollisionTrigger(m_player, OtherTakesDamage);

            GameObject2D m_end = new GameObject2D("end", "end");
            m_end.pos2D = m_grid.GetPoint(0.99f, 0.5f);
            //m_end.SetCustomBoundingBox(new Rectangle(new Point((int)m_end.pos2D.X, (int)m_end.pos2D.X), new Point((int)m_end.pos2D.X + 100, (int)m_end.pos2D.X + 100)));
            m_player.AddCollisionTrigger(m_end, PassLevel);

            //m_player.AddCollisionTrigger("hideloc", PlayerHides);

            // m_player.AddCollisionTrigger(m_testEnemy, OtherTakesDamage);

            //m_testEnemy.AddCollisionTrigger(m_player, EnemyHitsPlayer);







            m_textures = LoadTextures(m_texArray, texDir);

            Console.WriteLine("Initialisation complete.");

        }
        int m_levelsPassed = 0;
        int m_totalLevels = 1;

        void PassLevel(GameTime gameTime, GameObject2D thisobj, GameObject2D other)
        {

            Console.WriteLine("You have completed the level!");
            m_levelsPassed += 1;
            if(m_levelsPassed>=m_totalLevels)
            {
                Win(gameTime, thisobj, other);
            }
        }

        void Win(GameTime gameTime, GameObject2D thisobj, GameObject2D other)
        {
            Console.WriteLine("You have won!");
        }

        void OtherTakesDamage(GameTime gameTime, GameObject2D thisobj, GameObject2D other)
        {

            //Console.WriteLine("Collision event triggered: Player hit enemy.");
            
            other.RegisterHit(gameTime, 10);
        }

        /*
        void PlayerHides(GameTime gameTime, Player thisobj, GameObject2D other)
        {
            player.hiding = true;
        }
        */


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
