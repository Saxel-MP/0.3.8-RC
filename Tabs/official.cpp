namespace SAMP.Client.Data.Queries.Implementations
{
    public class ServerListQuery : IServerListQuery
    {
        readonly string _versionString = "0.3.8";

        readonly string _hostedActionUrl;
        readonly string _allActionUrl;

        public ServerListQuery()
        {
            _hostedActionUrl    = String.Format("{0}/official", _versionString); // official samp servers
            _allActionUrl       = String.Format("{0}/servers", _versionString); // internet tab servers
        }

        public List<Models.Server> All()
        {
            return AllEnumerable().ToList();
        }

        private IEnumerable<Models.Server> AllEnumerable()
        {
            using (var httpClient = new HttpClient { BaseAddress = new Uri("http://lists.sa-mp.com") })
            {
                httpClient.DefaultRequestHeaders.Add("User-Agent", "Mozilla/3.0 (compatible; SA:MP //)");

                var allServers      = GetAllTask(httpClient);
                var hostedServers   = GetHostedTask(httpClient).Result.ToList();

                foreach (var server in allServers.Result)
                {
                    var hostedServer= hostedServers.FirstOrDefault(x => x.Equals(server));
                    server.IsHosted = hostedServer != null;
                    hostedServers.Remove(hostedServer);
                    yield return server;
                }
            }
}
