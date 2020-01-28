import java.awt.BorderLayout;
import java.awt.Dimension;

import javax.swing.AbstractAction;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JToolBar;

import java.awt.event.*;
import java.net.UnknownHostException;

import javax.swing.*; //donne accès aux composants de Swing
import java.io.*;
import java.net.*;

/**
 *  A MainFrame class. Enables to start the program and launch the client interface.
 */


public class MainFrame extends JFrame implements ActionListener{

        public static void main(String[] args) throws UnknownHostException
        {
                // TODO Auto-generated method stub

                new MainFrame();
        };

        private static final long serialVersionUID = 1L;

        private JTextArea textArea = null;
        // enables to differentiate the buttons between them
        private JButton button1=null;
        private JButton button2=null;
        private JButton button3=null;

        private Client client = null;
        static final String DEFAULT_HOST = "localhost";
        static final int DEFAULT_PORT = 3331;


        // creates Abstract Actions depending on the object tackled
        private AbstractAction playRequestAction;
        private AbstractAction findRequestAction;
        private AbstractAction exitAction;

        /**
         * A constructor.
         * Constructs the Main Frame.
         */
        public MainFrame() throws UnknownHostException
        {

                // creation of a new client try/catch
                try
                {
                    client = new Client(DEFAULT_HOST, DEFAULT_PORT);
                }
                catch (Exception e)
                {
                    System.err.println("Client: Couldn't connect to localhost :" + DEFAULT_PORT);
                    System.exit(1);
                }

                  /**
                   * An Abstract Action variable.
                   * In a Popup Input Dialog Frame, the client enters the name of the object/group he wants to research in the table.
                   */
                findRequestAction = new AbstractAction("Find") {
                        private static final long serialVersionUID = 1L;

                        @Override
                        public void actionPerformed(ActionEvent arg0) {
                                // TODO Auto-generated method stub

                            // Show a dialog asking user to type in the request
                            String name = JOptionPane.showInputDialog("Entrer le nom du groupe que vous souhaitez trouver", "");
                            String request = "find " + name;
                            if (client != null){

                                String response = client.send(request) + " ";
                                textArea.append("\n ** Search Multimedia Object or Group in the table. ** ");
                                if (response != null){
                                    textArea.append("\n Reponse : " + response);
                                }
                                else
                                {
                                    textArea.append("\n No response. ");
                                }
                            }
                    }
                };

                playRequestAction = new AbstractAction("Play") {
                        private static final long serialVersionUID = 1L;

                        @Override
                        public void actionPerformed(ActionEvent arg0) {
                                // TODO Auto-generated method stub

                            String name = JOptionPane.showInputDialog("Entrer le nom du groupe que vous souhaitez trouver", "");
                            String request = "play " + name;
                            if (client != null){

                                textArea.append("\n ** Search to play Multimedia in table. ** ");
                                String response = client.send(request) + " ";
                                if (response != null)
                                {
                                    textArea.append("\n Reponse : " + response);
                                }
                                else
                                {
                                    textArea.append("\n No response. ");
                                }

                            }
                        }


                };

                exitAction = new AbstractAction("Exit") {
                        private static final long serialVersionUID = 1L;

                        @Override
                        public void actionPerformed(ActionEvent arg0) {
                                // TODO Auto-generated method stub
                            System.exit(0);
                        }
                };

                JFrame frame = new JFrame();
                frame.setLayout(new BorderLayout());
                frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

                initFrame();
                initMenuBar();
                initToolBar();

                this.pack();
                this.setVisible(true);



        }

        private void initFrame()
        {
                this.setPreferredSize(new Dimension(700,700));

                String text = "Connected to : " + DEFAULT_HOST + " "+ DEFAULT_PORT + " ";
                textArea = new JTextArea();
                textArea.append(text);
                textArea.setLineWrap(true);

                JScrollPane scrollPane = new JScrollPane(this.textArea);
                scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
                scrollPane.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
                this.add(scrollPane, BorderLayout.CENTER);

                JPanel panel = new JPanel();

                button1 = new JButton("Find");
                button2 = new JButton("Play");
                button3 = new JButton("Exit");

                button1.addActionListener(findRequestAction);
                button2.addActionListener(playRequestAction);
                button3.addActionListener(exitAction);

                panel.add(button1);
                panel.add(button2);
                panel.add(button3);

                this.add(panel, BorderLayout.SOUTH);
        }

        //  ** QUESTION 2 SWING ***
        public void actionPerformed(ActionEvent e) {
                // TODO Auto-generated method stub
                Object source = e.getSource();

                if (source == button3)
                {
                        // enables to exit the current program by terminating running Java virtual machine
                        System.exit(0);
                }
                else
                {
                        textArea.append("\n A new line was added from :");
                }

        }

        private void initMenuBar()
        {
                JMenuBar bar = new JMenuBar();

                JMenu menu = new JMenu("File");

                JMenuItem item1 = new JMenuItem("Find");
                JMenuItem item2 = new JMenuItem("Play");
                JMenuItem exit = new JMenuItem("Exit");

                menu.add(item1);
                menu.add(item2);
                menu.add(exit);
                item1.addActionListener(findRequestAction);
                item2.addActionListener(playRequestAction);
                exit.addActionListener(exitAction);

                bar.add(menu);

                this.setJMenuBar(bar);
        }

        private void initToolBar()
        {
                JToolBar toolBar = new JToolBar("Tool Bar");

                button1 = new JButton("Find");
                button2 = new JButton("Play");
                button3 = new JButton("Exit");

                button1.addActionListener(findRequestAction);
                button2.addActionListener(playRequestAction);
                button3.addActionListener(exitAction);

                toolBar.add(button1);
                toolBar.add(button2);
                toolBar.add(button3);

                this.add(toolBar, BorderLayout.NORTH);

        }


}

