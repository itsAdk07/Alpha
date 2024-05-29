using System.ComponentModel.DataAnnotations;

namespace NCCProj.Models
{
    public class users
    {
        [Key]
        public int id { get; set; }
        public string name { get; set; }
        public string contact { get; set; }
    }
}
